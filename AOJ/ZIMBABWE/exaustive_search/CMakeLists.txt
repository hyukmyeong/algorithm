cmake_minimum_required(VERSION 3.10)

add_executable(foo main.cpp)
target_compile_options(foo PRIVATE -g)
