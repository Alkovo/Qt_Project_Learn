# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Learn_01_Connect_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Learn_01_Connect_autogen.dir\\ParseCache.txt"
  "Learn_01_Connect_autogen"
  )
endif()
