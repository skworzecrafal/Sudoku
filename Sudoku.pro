#-------------------------------------------------
#
# Project created by QtCreator 2013-10-27T21:39:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sudoku
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    generacja.cpp \
    komorka.cpp \
    wynik.cpp \
    listawynikow.cpp \
    opcje.cpp \
    oknowyniki.cpp \
    dodajwynik.cpp

HEADERS  += mainwindow.h \
    generacja.h \
    komorka.h \
    wynik.h \
    listawynikow.h \
    opcje.h \
    oknowyniki.h \
    dodajwynik.h

FORMS    += mainwindow.ui
