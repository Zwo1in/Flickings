#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)

project(flicking)



include_directories("${PROJECT_BINARY_DIR}")

set(EXECUTABLE_NAME "flick")
add_executable(${EXECUTABLE_NAME} main.cpp)

find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
