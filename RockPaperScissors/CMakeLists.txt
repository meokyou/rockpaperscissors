# CMakeList.txt : CMake project for RockPaperScissors, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (RockPaperScissors "RockPaperScissors.cpp" "RockPaperScissors.h" "Game.cpp" "Game.h" "OrderStatisticTree.h"  "Utility.h" "Utility.cpp" "header.inc")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RockPaperScissors PROPERTY CXX_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
