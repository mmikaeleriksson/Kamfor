TEMPLATE = app
TARGET = Kamfor

INCLUDEPATH += .

QT += gui widgets

QMAKE_CC=clang++
QMAKE_CXX=clang++
QMAKE_LINK=clang++
CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

# disables all the APIs deprecated before Qt 6.0.0
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

OBJECTS_DIR=generated_files
MOC_DIR=generated_files

# Input
SOURCES += src/*.cpp
HEADERS += src/*.h
FORMS += src/*.ui

release: DESTDIR = bin/release
debug:   DESTDIR = bin/debug

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.iu
