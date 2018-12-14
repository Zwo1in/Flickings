cmake_minimum_required(VERSION 3.0.2)

project(flocking)

set(BUILD_SHARED_LIBS ON)

set(INCLUDE_DIRS  ${PROJECT_SOURCE_DIR}/include)
set(SRC_DIR       ${PROJECT_SOURCE_DIR}/src)
set(LIB_DIR       ${PROJECT_SOURCE_DIR}/lib)
set(BIN_DIR       ${PROJECT_SOURCE_DIR}/bin)
set(MODULE_DIR    ${PROJECT_SOURCE_DIR}/modules)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /usr/share/SFML/cmake/Modules/)
find_package(SFML REQUIRED COMPONENTS graphics window system)
set(INCLUDE_DIRS ${INCLUDE_DIRS} ${SFML_INCLUDE_DIR})

include_directories(${INCLUDE_DIRS})

add_subdirectory(${MODULE_DIR})
add_subdirectory(${SRC_DIR})

set(EXECUTABLE_NAME "flock")
set(EXECUTABLE_OUTPUT_PATH ${BIN_DIR})

add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(flock utility modules)
