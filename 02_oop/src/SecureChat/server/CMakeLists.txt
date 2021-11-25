add_executable(Server
            server.cpp)
            
set(CMAKE_INCLUDE_CURRENT_DIR ON)

target_include_directories(Server
            PRIVATE
                    Network)

target_link_libraries(Server
                    PRIVATE
                            Network)
