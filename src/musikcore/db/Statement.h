//////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2004-2021 musikcube team
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright notice,
//      this list of conditions and the following disclaimer.
//
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//
//    * Neither the name of the author nor the names of other contributors may
//      be used to endorse or promote products derived from this software
//      without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////////

#pragma once

#include <musikcore/config.h>
#include <map>

struct sqlite3_stmt;

namespace musik { namespace core { namespace db {

    class Connection;

    class Statement {
        public:
            DELETE_CLASS_DEFAULTS(Statement)

            Statement(const char* sql, Connection &connection) noexcept;
            virtual ~Statement() noexcept;

            void BindInt32(int position, int bindInt) noexcept;
            void BindInt64(int position, int64_t bindInt) noexcept;
            void BindFloat(int position, float bindFloat) noexcept;
            void BindText(int position, const std::string& bindText);
            void BindNull(int position) noexcept;

            const int ColumnInt32(int column) noexcept;
            const int64_t ColumnInt64(int column) noexcept;
            const float ColumnFloat(int column) noexcept;
            const char* ColumnText(int column) noexcept;
            const bool IsNull(int column) noexcept;

            int Step();

            void Reset() noexcept;
            void Unbind() noexcept;
            void ResetAndUnbind() noexcept;

        private:
            friend class Connection;

            Statement(Connection &connection) noexcept;

            sqlite3_stmt *stmt;
            Connection *connection;
            int modifiedRows;
    };

} } }

