add_library(Network STATIC)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
target_sources(Network
        PUBLIC socket.h
        PRIVATE socket.cpp)

target_include_directories(Network
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

