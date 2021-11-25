add_executable(Server
            server.cpp)
            
set(CMAKE_INCLUDE_CURRENT_DIR ON)

target_include_directories(Client
            PRIVATE
                    Network)

#target_link_libraries(Client
##[[                    PRIVATE
#                            Network]])
