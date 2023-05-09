cmake_minimum_required(VERSION 3.25)
project(progetto_sistemi_operativi C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(progetto_sistemi_operativi
        defines.c
        defines.h
        err_exit.c
        err_exit.h
        F4Client.c
        F4Server.c
        fifo.c
        fifo.h
        semaphore.c
        semaphore.h
        shared_memory.c
        shared_memory.h debug.c debug.h)
