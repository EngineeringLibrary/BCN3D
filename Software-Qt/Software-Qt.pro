#-------------------------------------------------
#
# Project created by QtCreator 2017-10-31T18:42:34
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Software-Qt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    binaryimage.cpp \
    client.cpp \
    result_view.cpp

HEADERS  += mainwindow.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h \
    SistemasdeControle/src/primitiveLibs/LinAlg/matrix.hpp \
    imageconversion.h \
    imageconversion.hpp \
    imageprocessing.h \
    imageprocessing.hpp \
    rgbimage.h \
    rgbimage.hpp \
    grayimage.h \
    grayimage.hpp \
    binaryimage.h \
    client.h \
    result_view.h \
    ui_result_view \
    SistemasdeControle/headers/optimizationLibs/pso.h \
    SistemasdeControle/src/optimizationLibs/pso.hpp \
    SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h \
    SistemasdeControle/src/primitiveLibs/LinAlg/linalg.hpp


FORMS    += mainwindow.ui \
    result_view.ui

RC_FILE = myapp.rc

DISTFILES += \
    bcn3d.ico
