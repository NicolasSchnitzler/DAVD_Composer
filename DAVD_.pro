#-------------------------------------------------
#
# Project created by QtCreator 2014-12-22T16:43:30
#
#-------------------------------------------------


QT       += core gui xml widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DAVD
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
    dtkCreatorMainWindow.cpp \
    davdcomposernodefactory.cpp \
    Image.cpp \
    SegmentationProcess.cpp \
    FilterProcess.cpp \
    nodes/FilterNode.cpp \
    nodes/ImageReaderNode.cpp \
    nodes/ImageWriterNode.cpp \
    nodes/SegmentationNode.cpp \
    pixmapwrapper.cpp \
    pixmapreaderclass.cpp \
    drawablelabel.cpp \
    interactivecomposernode.cpp



LIBS += /user/nschnitz/home/Development/dtk1/build/lib64/*

INCLUDEPATH += /user/nschnitz/home/Development/dtk1/src /user/nschnitz/home/Development/dtk1/build

HEADERS += \
    dtkCreatorMainWindow_p.h \
    dtkCreatorMainWindow.h \
    davdcomposernodefactory.h \
    Image.h \
    SegmentationProcess_p.h \
    SegmentationProcess.h \
    FilterProcess_p.h \
    FilterProcess.h \
    nodes/FilterNode.h \
    nodes/ImageReaderNode.h \
    nodes/ImageWriterNode.h \
    nodes/SegmentationNode.h \
    pixmapwrapper.h \
    pixmapreaderclass.h \
    Image_p.h \
    drawablelabel.h \
    interactivecomposernode.h
