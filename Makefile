#############################################################################
# Makefile for building: GoL
# Generated by qmake (2.01a) (Qt 4.8.1) on: Thu Aug 1 11:53:38 2013
# Project:  GoL.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile GoL.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = about.cpp \
		board.cpp \
		globalpointers.cpp \
		main.cpp \
		mainwindow.cpp \
		settingsdialog.cpp \
		simplegame.cpp \
		square.cpp \
		statusandcontrol.cpp moc_about.cpp \
		moc_board.cpp \
		moc_mainwindow.cpp \
		moc_settingsdialog.cpp \
		moc_simplegame.cpp \
		moc_square.cpp \
		moc_statusandcontrol.cpp
OBJECTS       = about.o \
		board.o \
		globalpointers.o \
		main.o \
		mainwindow.o \
		settingsdialog.o \
		simplegame.o \
		square.o \
		statusandcontrol.o \
		moc_about.o \
		moc_board.o \
		moc_mainwindow.o \
		moc_settingsdialog.o \
		moc_simplegame.o \
		moc_square.o \
		moc_statusandcontrol.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		GoL.pro
QMAKE_TARGET  = GoL
DESTDIR       = 
TARGET        = GoL

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_about.h ui_settingsdialog.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: GoL.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile GoL.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile GoL.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/GoL1.0.0 || $(MKDIR) .tmp/GoL1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/GoL1.0.0/ && $(COPY_FILE) --parents about.h board.h defaultsettings.h globalpointers.h mainwindow.h settingsdialog.h simplegame.h square.h statusandcontrol.h .tmp/GoL1.0.0/ && $(COPY_FILE) --parents about.cpp board.cpp globalpointers.cpp main.cpp mainwindow.cpp settingsdialog.cpp simplegame.cpp square.cpp statusandcontrol.cpp .tmp/GoL1.0.0/ && $(COPY_FILE) --parents about.ui settingsdialog.ui .tmp/GoL1.0.0/ && (cd `dirname .tmp/GoL1.0.0` && $(TAR) GoL1.0.0.tar GoL1.0.0 && $(COMPRESS) GoL1.0.0.tar) && $(MOVE) `dirname .tmp/GoL1.0.0`/GoL1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/GoL1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_about.cpp moc_board.cpp moc_mainwindow.cpp moc_settingsdialog.cpp moc_simplegame.cpp moc_square.cpp moc_statusandcontrol.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_about.cpp moc_board.cpp moc_mainwindow.cpp moc_settingsdialog.cpp moc_simplegame.cpp moc_square.cpp moc_statusandcontrol.cpp
moc_about.cpp: about.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) about.h -o moc_about.cpp

moc_board.cpp: square.h \
		globalpointers.h \
		statusandcontrol.h \
		simplegame.h \
		defaultsettings.h \
		board.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) board.h -o moc_board.cpp

moc_mainwindow.cpp: mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_settingsdialog.cpp: settingsdialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) settingsdialog.h -o moc_settingsdialog.cpp

moc_simplegame.cpp: defaultsettings.h \
		simplegame.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) simplegame.h -o moc_simplegame.cpp

moc_square.cpp: globalpointers.h \
		statusandcontrol.h \
		simplegame.h \
		defaultsettings.h \
		square.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) square.h -o moc_square.cpp

moc_statusandcontrol.cpp: statusandcontrol.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) statusandcontrol.h -o moc_statusandcontrol.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_about.h ui_settingsdialog.h
compiler_uic_clean:
	-$(DEL_FILE) ui_about.h ui_settingsdialog.h
ui_about.h: about.ui
	/usr/bin/uic-qt4 about.ui -o ui_about.h

ui_settingsdialog.h: settingsdialog.ui
	/usr/bin/uic-qt4 settingsdialog.ui -o ui_settingsdialog.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

about.o: about.cpp about.h \
		ui_about.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o about.o about.cpp

board.o: board.cpp board.h \
		square.h \
		globalpointers.h \
		statusandcontrol.h \
		simplegame.h \
		defaultsettings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o board.o board.cpp

globalpointers.o: globalpointers.cpp globalpointers.h \
		statusandcontrol.h \
		simplegame.h \
		defaultsettings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o globalpointers.o globalpointers.cpp

main.o: main.cpp square.h \
		globalpointers.h \
		statusandcontrol.h \
		simplegame.h \
		defaultsettings.h \
		board.h \
		mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp simplegame.h \
		defaultsettings.h \
		mainwindow.h \
		board.h \
		square.h \
		globalpointers.h \
		statusandcontrol.h \
		about.h \
		settingsdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

settingsdialog.o: settingsdialog.cpp settingsdialog.h \
		ui_settingsdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o settingsdialog.o settingsdialog.cpp

simplegame.o: simplegame.cpp simplegame.h \
		defaultsettings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o simplegame.o simplegame.cpp

square.o: square.cpp square.h \
		globalpointers.h \
		statusandcontrol.h \
		simplegame.h \
		defaultsettings.h \
		board.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o square.o square.cpp

statusandcontrol.o: statusandcontrol.cpp statusandcontrol.h \
		globalpointers.h \
		simplegame.h \
		defaultsettings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o statusandcontrol.o statusandcontrol.cpp

moc_about.o: moc_about.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_about.o moc_about.cpp

moc_board.o: moc_board.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_board.o moc_board.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_settingsdialog.o: moc_settingsdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_settingsdialog.o moc_settingsdialog.cpp

moc_simplegame.o: moc_simplegame.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_simplegame.o moc_simplegame.cpp

moc_square.o: moc_square.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_square.o moc_square.cpp

moc_statusandcontrol.o: moc_statusandcontrol.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_statusandcontrol.o moc_statusandcontrol.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

