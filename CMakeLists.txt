cmake_minimum_required(VERSION 3.0)
project(minesweeper)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_STANDARD 14)

include_directories(
    src/
)

find_package(PkgConfig REQUIRED)
set(SFML_USE_STATIC_STD_LIBS TRUE)

add_executable(
    minesweeper_gui
    src/game/board.cpp
    src/game/node.cpp
    src/gui/gui.cpp
    src/main_gui.cpp
)
target_link_libraries(
    minesweeper_gui
    sfml-system
    sfml-window
    sfml-graphics
    sfml-network
    sfml-audio
)
