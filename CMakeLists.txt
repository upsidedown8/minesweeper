cmake_minimum_required(VERSION 3.0)
project(minesweeper)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_STANDARD 14)

include_directories(
    src/
)

set(
    SRC_FILES
    src/main.cpp
    src/board.cpp
    src/game.cpp
    src/node.cpp
)

add_executable(
    minesweeper_exec
    ${SRC_FILES}
)

