cmake_minimum_required(VERSION 3.5.0)
project(GoL VERSION 0.1.0)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 11)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Add the executable
add_executable(GoL
        board.cpp
        globalpointers.cpp
        main.cpp
        mainwindow.cpp
        settingsdialog.cpp
        simplegame.cpp
        square.cpp
        statusandcontrol.cpp

        board.h
        defaultsettings.h
        globalpointers.h
        mainwindow.h
        settingsdialog.h
        simplegame.h
        square.h
        statusandcontrol.h

        settingsdialog.ui
        )

# Use the Widgets module from Qt 5
target_link_libraries(GoL Qt5::Widgets)
