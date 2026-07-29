cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME "OPTIC")
project(${LIBRARY_NAME} VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${LIBRARY_NAME}
    src/runtime/runtime.cpp

    src/window/window.cpp

    src/nodes/node.cpp
        #src/nodes/text/text.cpp
        src/nodes/rectangle/rectangle.cpp
)

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_ttf REQUIRED)

target_link_libraries(${LIBRARY_NAME} PUBLIC SDL3::SDL3 SDL3_image::SDL3_image SDL3_ttf::SDL3_ttf)

target_include_directories(${LIBRARY_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)


# EXAMPLE PROGRAM

set(EXAMPLE_NAME "example")

add_executable(${EXAMPLE_NAME}
    example/interface.cpp
    example/behavior.cpp
)

set_target_properties(${EXAMPLE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/example
)

target_link_libraries(${EXAMPLE_NAME}
    PRIVATE ${LIBRARY_NAME}
)
