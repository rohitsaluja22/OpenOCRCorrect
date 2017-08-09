#-------------------------------------------------
#
# Project created by QtCreator 2016-06-13T18:03:39
#
#-------------------------------------------------

QT       += core gui
QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qpadfinal
TEMPLATE = app

#LIBS += -L"/home/rohit/ExpFinal/2OCRCorrect"
#LIBS += -L"/usr/local/bin/tesseract"

#LIBS += -L"/usr/local/lib" -llept\
#        -ltesseract

#LIBS += -L"/home/nilesh/OCRCorrection/boost_1_61_0/stage/lib" -lboost_serialization

SOURCES +=\
        mainwindow.cpp \
    main.cpp \
    zoom.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    eddis.h \
    slpNPatternDict.h \
    trieEditdis.h \
    zoom.h \
    qcustomplot.h \
    meanStdPage.h

FORMS    += mainwindow.ui

RESOURCES += \
    AppResources.qrc

CONFIG += c++11
