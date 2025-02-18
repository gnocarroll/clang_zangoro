cmake_minimum_required(VERSION 3.31)
project(zangoro)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

add_executable(zangoro)

target_include_directories(zangoro
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)

add_subdirectory(src)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
target_link_libraries(zangoro PRIVATE SDL3::SDL3)
