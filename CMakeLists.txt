cmake_minimum_required(VERSION 3.14)

set(LIBRARY_NAME "OPTIC")
project(${LIBRARY_NAME} VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(${LIBRARY_NAME}
    src/root.cpp
)

target_include_directories(${LIBRARY_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)


set(EXAMPLE_NAME "OPTIC_TEST")

add_executable(${EXAMPLE_NAME}
    example.cpp
)

target_link_libraries(${EXAMPLE_NAME}
    PRIVATE ${LIBRARY_NAME}
)