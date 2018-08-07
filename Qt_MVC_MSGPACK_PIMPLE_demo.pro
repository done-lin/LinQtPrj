#-------------------------------------------------
#
# Project created by QtCreator 2018-07-11T10:51:35
#
#-------------------------------------------------
# this project is use by done lin, it is tested on linux Ubuntu x64, and Android(compile by Qt5.6.1)
# alread recompiled the qmsgpack library, the libaray url: https://github.com/done-lin/QmsgPackForLinuxAndAndroid
#
# this project's github url: https://github.com/done-lin/LinQtPrj

QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt_MVC_MSGPACK_PIMPLE_demo
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


SOURCES += main.cpp\
        qtmvcwindow.cpp \
    qtmvcwindowprivate.cpp \
    qmsgpack-master/src/private/pack_p.cpp \
    qmsgpack-master/src/private/qt_types_p.cpp \
    qmsgpack-master/src/private/unpack_p.cpp \
    qmsgpack-master/src/stream/geometry.cpp \
    qmsgpack-master/src/stream/location.cpp \
    qmsgpack-master/src/stream/time.cpp

HEADERS  += qtmvcwindow.h \
    qtmvcwindowprivate.h \
    qmsgpack-master/src/endianhelper.h \
    qmsgpack-master/src/msgpack.h \
    qmsgpack-master/src/msgpack_export.h \
    qmsgpack-master/src/msgpackcommon.h \
    qmsgpack-master/src/msgpackstream.h \
    qmsgpack-master/src/private/pack_p.h \
    qmsgpack-master/src/private/qt_types_p.h \
    qmsgpack-master/src/private/unpack_p.h \
    qmsgpack-master/src/stream/geometry.h \
    qmsgpack-master/src/stream/location.h \
    qmsgpack-master/src/stream/time.h

FORMS    += qtmvcwindow.ui

INCLUDEPATH += qmsgpack-master/src/ -I$$PWD/qmsgpack-master/src -I.

unix {
LIBS += -L$$PWD/qmsgpack_libs_for_linux_x64_desktop/ -lqmsgpackd
LIBS += -L$$PWD/qmsgpack_libs_for_android/ -lqmsgpackd
}

win32{
LIBS += -L$$PWD\qmsgpack-master\bin -lqmsgpackd
}
