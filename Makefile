#############################################################################
# Makefile for building: hw8
# Generated by qmake (2.01a) (Qt 4.8.6) on: Thu Sep 3 22:38:28 2015
# Project:  hw8.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile hw8.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
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

SOURCES       = book.cpp \
		clothing.cpp \
		db_parser.cpp \
		ddatastore.cpp \
		dialog.cpp \
		logindialog.cpp \
		main_window.cpp \
		movie.cpp \
		msort.cpp \
		newUserDialog.cpp \
		product.cpp \
		product_parser.cpp \
		recommenddialog.cpp \
		reviewdialog.cpp \
		splay.cpp \
		user.cpp \
		util.cpp moc_dialog.cpp \
		moc_logindialog.cpp \
		moc_main_window.cpp \
		moc_newUserDialog.cpp \
		moc_recommenddialog.cpp \
		moc_reviewdialog.cpp
OBJECTS       = book.o \
		clothing.o \
		db_parser.o \
		ddatastore.o \
		dialog.o \
		logindialog.o \
		main_window.o \
		movie.o \
		msort.o \
		newUserDialog.o \
		product.o \
		product_parser.o \
		recommenddialog.o \
		reviewdialog.o \
		splay.o \
		user.o \
		util.o \
		moc_dialog.o \
		moc_logindialog.o \
		moc_main_window.o \
		moc_newUserDialog.o \
		moc_recommenddialog.o \
		moc_reviewdialog.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
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
		hw8.pro
QMAKE_TARGET  = hw8
DESTDIR       = 
TARGET        = hw8

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

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: hw8.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
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
	$(QMAKE) -o Makefile hw8.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
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
	@$(QMAKE) -o Makefile hw8.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/hw81.0.0 || $(MKDIR) .tmp/hw81.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/hw81.0.0/ && $(COPY_FILE) --parents book.h bst.h clothing.h comparison.h datastore.h db_parser.h ddatastore.h dialog.h hash.h heap.h logindialog.h main_window.h movie.h msort.h newUserDialog.h product.h product_parser.h recommenddialog.h review.h reviewdialog.h splay.h user.h util.h .tmp/hw81.0.0/ && $(COPY_FILE) --parents book.cpp clothing.cpp db_parser.cpp ddatastore.cpp dialog.cpp logindialog.cpp main_window.cpp movie.cpp msort.cpp newUserDialog.cpp product.cpp product_parser.cpp recommenddialog.cpp reviewdialog.cpp splay.cpp user.cpp util.cpp .tmp/hw81.0.0/ && (cd `dirname .tmp/hw81.0.0` && $(TAR) hw81.0.0.tar hw81.0.0 && $(COMPRESS) hw81.0.0.tar) && $(MOVE) `dirname .tmp/hw81.0.0`/hw81.0.0.tar.gz . && $(DEL_FILE) -r .tmp/hw81.0.0


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

compiler_moc_header_make_all: moc_dialog.cpp moc_logindialog.cpp moc_main_window.cpp moc_newUserDialog.cpp moc_recommenddialog.cpp moc_reviewdialog.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_dialog.cpp moc_logindialog.cpp moc_main_window.cpp moc_newUserDialog.cpp moc_recommenddialog.cpp moc_reviewdialog.cpp
moc_dialog.cpp: ddatastore.h \
		datastore.h \
		product.h \
		review.h \
		user.h \
		book.h \
		util.h \
		clothing.h \
		movie.h \
		splay.h \
		bst.h \
		main_window.h \
		dialog.h \
		reviewdialog.h \
		logindialog.h \
		newUserDialog.h \
		recommenddialog.h \
		heap.h \
		dialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) dialog.h -o moc_dialog.cpp

moc_logindialog.cpp: ddatastore.h \
		datastore.h \
		product.h \
		review.h \
		user.h \
		book.h \
		util.h \
		clothing.h \
		movie.h \
		splay.h \
		bst.h \
		newUserDialog.h \
		logindialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) logindialog.h -o moc_logindialog.cpp

moc_main_window.cpp: dialog.h \
		ddatastore.h \
		datastore.h \
		product.h \
		review.h \
		user.h \
		book.h \
		util.h \
		clothing.h \
		movie.h \
		splay.h \
		bst.h \
		main_window.h \
		reviewdialog.h \
		logindialog.h \
		newUserDialog.h \
		recommenddialog.h \
		heap.h \
		main_window.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) main_window.h -o moc_main_window.cpp

moc_newUserDialog.cpp: ddatastore.h \
		datastore.h \
		product.h \
		review.h \
		user.h \
		book.h \
		util.h \
		clothing.h \
		movie.h \
		splay.h \
		bst.h \
		newUserDialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) newUserDialog.h -o moc_newUserDialog.cpp

moc_recommenddialog.cpp: ddatastore.h \
		datastore.h \
		product.h \
		review.h \
		user.h \
		book.h \
		util.h \
		clothing.h \
		movie.h \
		splay.h \
		bst.h \
		recommenddialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) recommenddialog.h -o moc_recommenddialog.cpp

moc_reviewdialog.cpp: ddatastore.h \
		datastore.h \
		product.h \
		review.h \
		user.h \
		book.h \
		util.h \
		clothing.h \
		movie.h \
		splay.h \
		bst.h \
		main_window.h \
		dialog.h \
		reviewdialog.h \
		logindialog.h \
		newUserDialog.h \
		recommenddialog.h \
		heap.h \
		reviewdialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) reviewdialog.h -o moc_reviewdialog.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

book.o: book.cpp product.h \
		review.h \
		util.h \
		book.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o book.o book.cpp

clothing.o: clothing.cpp product.h \
		review.h \
		util.h \
		clothing.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o clothing.o clothing.cpp

db_parser.o: db_parser.cpp db_parser.h \
		datastore.h \
		product.h \
		review.h \
		user.h \
		product_parser.h \
		book.h \
		util.h \
		clothing.h \
		movie.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o db_parser.o db_parser.cpp

ddatastore.o: ddatastore.cpp ddatastore.h \
		datastore.h \
		product.h \
		review.h \
		user.h \
		book.h \
		util.h \
		clothing.h \
		movie.h \
		splay.h \
		bst.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ddatastore.o ddatastore.cpp

dialog.o: dialog.cpp dialog.h \
		ddatastore.h \
		datastore.h \
		product.h \
		review.h \
		user.h \
		book.h \
		util.h \
		clothing.h \
		movie.h \
		splay.h \
		bst.h \
		main_window.h \
		reviewdialog.h \
		logindialog.h \
		newUserDialog.h \
		recommenddialog.h \
		heap.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dialog.o dialog.cpp

logindialog.o: logindialog.cpp reviewdialog.h \
		ddatastore.h \
		datastore.h \
		product.h \
		review.h \
		user.h \
		book.h \
		util.h \
		clothing.h \
		movie.h \
		splay.h \
		bst.h \
		main_window.h \
		dialog.h \
		logindialog.h \
		newUserDialog.h \
		recommenddialog.h \
		heap.h \
		hash.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o logindialog.o logindialog.cpp

main_window.o: main_window.cpp main_window.h \
		dialog.h \
		ddatastore.h \
		datastore.h \
		product.h \
		review.h \
		user.h \
		book.h \
		util.h \
		clothing.h \
		movie.h \
		splay.h \
		bst.h \
		reviewdialog.h \
		logindialog.h \
		newUserDialog.h \
		recommenddialog.h \
		heap.h \
		msort.h \
		comparison.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main_window.o main_window.cpp

movie.o: movie.cpp product.h \
		review.h \
		util.h \
		movie.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o movie.o movie.cpp

msort.o: msort.cpp msort.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o msort.o msort.cpp

newUserDialog.o: newUserDialog.cpp newUserDialog.h \
		ddatastore.h \
		datastore.h \
		product.h \
		review.h \
		user.h \
		book.h \
		util.h \
		clothing.h \
		movie.h \
		splay.h \
		bst.h \
		hash.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o newUserDialog.o newUserDialog.cpp

product.o: product.cpp product.h \
		review.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o product.o product.cpp

product_parser.o: product_parser.cpp product_parser.h \
		product.h \
		review.h \
		book.h \
		util.h \
		clothing.h \
		movie.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o product_parser.o product_parser.cpp

recommenddialog.o: recommenddialog.cpp recommenddialog.h \
		ddatastore.h \
		datastore.h \
		product.h \
		review.h \
		user.h \
		book.h \
		util.h \
		clothing.h \
		movie.h \
		splay.h \
		bst.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o recommenddialog.o recommenddialog.cpp

reviewdialog.o: reviewdialog.cpp reviewdialog.h \
		ddatastore.h \
		datastore.h \
		product.h \
		review.h \
		user.h \
		book.h \
		util.h \
		clothing.h \
		movie.h \
		splay.h \
		bst.h \
		main_window.h \
		dialog.h \
		logindialog.h \
		newUserDialog.h \
		recommenddialog.h \
		heap.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o reviewdialog.o reviewdialog.cpp

splay.o: splay.cpp splay.h \
		bst.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o splay.o splay.cpp

user.o: user.cpp user.h \
		product.h \
		review.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o user.o user.cpp

util.o: util.cpp util.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o util.o util.cpp

moc_dialog.o: moc_dialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_dialog.o moc_dialog.cpp

moc_logindialog.o: moc_logindialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_logindialog.o moc_logindialog.cpp

moc_main_window.o: moc_main_window.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_main_window.o moc_main_window.cpp

moc_newUserDialog.o: moc_newUserDialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_newUserDialog.o moc_newUserDialog.cpp

moc_recommenddialog.o: moc_recommenddialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_recommenddialog.o moc_recommenddialog.cpp

moc_reviewdialog.o: moc_reviewdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_reviewdialog.o moc_reviewdialog.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

