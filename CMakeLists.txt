cmake_minimum_required(VERSION 3.31)
project(zangoro)

add_executable(zangoro)

target_include_directories(zangoro
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)

add_subdirectory(src)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
target_link_libraries(zangoro PRIVATE SDL3::SDL3)
