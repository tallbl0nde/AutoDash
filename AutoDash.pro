#-------------------------------------------------
#
# Project created by QtCreator 2021-12-16T21:12:57
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++17
TARGET = AutoDash
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += \
    $$PWD/include

SOURCES += \
    $$files(source/*.cpp, true)

HEADERS += \
    $$files(include/*.hpp, true)
