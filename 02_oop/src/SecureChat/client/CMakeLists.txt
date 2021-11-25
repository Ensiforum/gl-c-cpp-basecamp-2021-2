
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(QT NAMES Qt5 COMPONENTS Core Gui Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)


add_executable(Client
            client.cpp
            mainwindow.h
            mainwindow.cpp
            mainwindow.ui)

target_include_directories(Client
            PRIVATE
                    Network)

target_link_libraries(Client
                    PUBLIC
                            #[[Network]]
                            Qt5::Core
                            Qt5::Widgets
                            Qt5::Gui
                            )







