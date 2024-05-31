QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = id3reader
TEMPLATE = app

CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/../debug
} else {
    DESTDIR = $$PWD/../release
    unix:{
        QMAKE_LFLAGS_RPATH=
        QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN/libs\'"
    }
}

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
CONFIG += c++14

HEADERS += \
        pch.h \
    binary.h \
    v22.h \
    v23.h \
    v24.h \
    v1.h \
    frame2.h \
    frame3.h \
    frame4.h \
    file-holder.h \
    tag.h \
    frame.h \
    tag34.h \
    frame_34.h \
    frame_structs.h \
    tag_structs.h \
    file_contents.h \
    char_conversions.h \
    file_structs.h \
    new_char_extracting.h \
    tagparser.h \
    frameparser.h \
    global_constants.h \
    widget.h \
    global_functions.h \
    debugfile.h \
    widget1.h

SOURCES += \
        main.cpp \
    binary.cpp \
    v22.cpp \
    v23.cpp \
    v24.cpp \
    v1.cpp \
    frame2.cpp \
    frame3.cpp \
    frame4.cpp \
    frames2.cpp \
    frames3.cpp \
    file-holder.cpp \
    tag.cpp \
    frame.cpp \
    tag34.cpp \
    frames4UEM.cpp \
    frames4text.cpp \
    frame_34.cpp \
    frames4unknown.cpp \
    file_contents.cpp \
    char_conversions.cpp \
    file_structs.cpp \
    monsterous_functions.cpp \
    new_char_extracting.cpp \
    tagparser.cpp \
    frameparser.cpp \
    widget.cpp \
    global_functions.cpp \
    debugfile.cpp \
    widget1.cpp

FORMS += \
    widget.ui

LIBS += -lz
