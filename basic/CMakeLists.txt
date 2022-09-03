cmake_minimum_required(VERSION 3.21)
project(basic C)

set(CMAKE_C_STANDARD 99)

#add_executable(basic main.c chapter3/getchar01.c)

add_executable(chapter3_getchar01 chapter3/getchar01.c)
add_executable(chapter3_gets01 chapter3/gets01.c)
add_executable(chapter3_escseq01 chapter3/escseq01.c)
add_executable(chapter3_charint01 chapter3/charint01.c)
add_executable(chapter3_intover01 chapter3/intover01.c)
add_executable(chapter3_longlongint chapter3/longlongint.c)