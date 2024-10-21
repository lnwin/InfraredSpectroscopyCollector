QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17
QT += printsupport
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    datachart.cpp \
    dataprocessing.cpp \
    datasaving.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    usbcard.cpp

HEADERS += \
    datachart.h \
    dataprocessing.h \
    datasaving.h \
    mainwindow.h \
    qcustomplot.h \
    usbcard.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/include/ -lUSB2070

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include
