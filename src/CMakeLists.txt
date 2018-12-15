cmake_minimum_required(VERSION 3.0.2)

set(SOURCES
    vec.cpp
    rand.cpp
    boid.cpp
    loop.cpp
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR})
add_library(utility ${SOURCES})
target_link_libraries(utility modules ${SFML_LIBRARIES})