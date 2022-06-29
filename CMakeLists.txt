cmake_minimum_required(VERSION 3.16)

project(clicker VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
    src/main.cpp
    src/mainwindow.h
    src/mainwindow.cpp
    src/gamecore.h
    src/gamecore.cpp
    src/gamefield.h
    src/gamefield.cpp
    src/statpanel.h
    src/statpanel.cpp
    src/controlpanel.h
    src/controlpanel.cpp
    src/togglingbutton.h
    src/togglingbutton.cpp
    src/goodbyedialog.h
    src/goodbyedialog.cpp
)

add_executable(clicker
    ${PROJECT_SOURCES}
)

target_link_libraries(clicker PRIVATE Qt5::Widgets)
