#-------------------------------------------------
#
# Project created by QtCreator 2019-03-10T16:25:26
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QDrink
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        bevanda.cpp \
        bevanda_alcolica.cpp \
        bevanda_analcolica.cpp \
        birra.cpp \
        data.cpp \
        model.cpp \
        te.cpp \
        vino.cpp \
         form.cpp \
    mywidgets.cpp \
    controller.cpp \
    mylist.cpp \
    visualizza.cpp \
    modifica.cpp

HEADERS += \
        mainwindow.h\
    bevanda.h \
    bevanda_alcolica.h \
    bevanda_analcolica.h \
    birra.h \
    container.h \
    model.h \
    te.h \
    vino.h \
    form.h \
    mywidgets.h \
    controller.h \
    data.h \
    mylist.h \
    visualizza.h \
    modifica.h
RC_ICONS = immagini/icona.ico
# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES +=
