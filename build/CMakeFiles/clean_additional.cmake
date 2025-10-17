# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\McuDownLoaderForCortex-M_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\McuDownLoaderForCortex-M_autogen.dir\\ParseCache.txt"
  "McuDownLoaderForCortex-M_autogen"
  )
endif()
