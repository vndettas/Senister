# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "CMakeFiles\\Veditor_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Veditor_autogen.dir\\ParseCache.txt"
  "Veditor_autogen"
  )
endif()
