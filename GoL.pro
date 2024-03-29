######################################################################
# Automatically generated by qmake (3.1) Sat Dec 2 15:44:40 2023
######################################################################

TEMPLATE = app
TARGET = GoL
INCLUDEPATH += .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += board.h \
           defaultsettings.h \
           globalpointers.h \
           mainwindow.h \
           settingsdialog.h \
           simplegame.h \
           square.h \
           statusandcontrol.h \
           build/GoL_autogen/include/ui_settingsdialog.h \
           cmake-build-debug/GoL_autogen/include/ui_settingsdialog.h
FORMS += settingsdialog.ui
SOURCES += board.cpp \
           globalpointers.cpp \
           main.cpp \
           mainwindow.cpp \
           settingsdialog.cpp \
           simplegame.cpp \
           square.cpp \
           statusandcontrol.cpp \
           build/CMakeFiles/3.16.3/CompilerIdC/CMakeCCompilerId.c \
           build/CMakeFiles/3.16.3/CompilerIdCXX/CMakeCXXCompilerId.cpp \
           cmake-build-debug/CMakeFiles/3.25.2/CompilerIdC/CMakeCCompilerId.c \
           cmake-build-debug/CMakeFiles/3.25.2/CompilerIdCXX/CMakeCXXCompilerId.cpp
