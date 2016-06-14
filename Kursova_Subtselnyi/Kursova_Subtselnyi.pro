#-------------------------------------------------
#
# Project created by QtCreator 2016-05-15T22:43:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kursova_Subtselnyi
TEMPLATE = app


SOURCES += main.cpp\
        graph.cpp \
    prima.cpp \
    kruskala.cpp \
    boruvka.cpp \
    WriteRead.cpp \
    researchGraph.cpp

HEADERS  += graph.h \
    prima.h \
    kruskala.h \
    variables.h \
    boruvka.h \
    WriteRead.h \
    researchGraph.h

FORMS    += graph.ui
