cmake_minimum_required(VERSION 3.0.2)

set(SOURCES
    game_clock/fpsClock.cpp
)
set(INCLUDES
    game_clock
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR})

add_library(modules ${SOURCES})
target_include_directories(modules PUBLIC ${INCLUDES})
target_link_libraries(modules ${SFML_LIBRARIES})