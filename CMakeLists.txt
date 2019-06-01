cmake_minimum_required(VERSION 3.10)
project(AutosarChecker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})

add_subdirectory(src)
target_include_directories(autosar_checker PRIVATE include)

