# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\RPG-game_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\RPG-game_autogen.dir\\ParseCache.txt"
  "RPG-game_autogen"
  )
endif()
