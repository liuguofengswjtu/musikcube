set (openmptdecoder_SOURCES
  plugin.cpp
  OpenMptDataStream.cpp
  OpenMptDecoder.cpp
  OpenMptIndexerSource.cpp
  Utility.cpp
)

add_library(openmptdecoder SHARED ${openmptdecoder_SOURCES})

# ensure vendor'd headers take priority over our local ones.
target_include_directories(openmptdecoder BEFORE PRIVATE ${VENDOR_INCLUDE_DIRECTORIES})

find_library(OPENMPTLIB NAMES openmpt)
find_library(MPG123LIB NAMES mpg123)
find_library(ZLIB NAMES z)
target_link_libraries(openmptdecoder ${OPENMPTLIB} ${MPG123LIB} ${ZLIB})
