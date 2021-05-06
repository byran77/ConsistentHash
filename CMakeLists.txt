cmake_minimum_required(VERSION 3.5)

project(consistentHash)

add_library(consistentHash STATIC
    ${PROJECT_SOURCE_DIR}/src/consistentHash.cpp
    ${PROJECT_SOURCE_DIR}/src/murmurHash3/murmurHash3.cpp
)

target_include_directories(consistentHash
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src/detail
)

add_executable(test
    ${PROJECT_SOURCE_DIR}/example/test.cpp
)

target_link_libraries(test
    PRIVATE
        consistentHash
)