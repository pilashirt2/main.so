cmake_minimum_required(VERSION 3.10.2)
project("ludoproxy")

add_library(
    main
    SHARED
    main.cpp
)

target_link_libraries(
    main
    log
)
