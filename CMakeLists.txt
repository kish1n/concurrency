cmake_minimum_required(VERSION 3.30)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "f35a9ac6-8463-4d38-8eec-5d6008153e7d")
set(CMAKE_CXX_MODULE_STD 1)
set(CMAKE_CXX_STANDARD 23)

project(concurrency)

add_library(concurrency)
target_sources(concurrency
    PUBLIC
    FILE_SET CXX_MODULES FILES
    concurrency/concurrency.cppm
    concurrency/spsc_queue.cppm
)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE concurrency)