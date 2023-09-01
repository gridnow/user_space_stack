cmake_minimum_required(VERSION 3.26)
project(user_space_stack C)

set(CMAKE_C_STANDARD 11)

#internal
include_directories("src/include")
#external
include_directories("include")

add_executable(user_space_stack main.c
        src/ptf/ptf.c
        src/ptf/udp.c
        src/uss.c
)
