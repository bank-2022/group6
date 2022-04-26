QT       += core gui
QT +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bankmain.cpp \
    main.cpp \
    mainwindow.cpp \
    myurl.cpp \
    pinikkuna.cpp

HEADERS += \
    bankmain.h \
    mainwindow.h \
    myurl.h \
    pinikkuna.h

FORMS += \
    bankmain.ui \
    mainwindow.ui \
    pinikkuna.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



win32: LIBS += -L$$PWD/../PinDll/build/debug/ -lPinDll

INCLUDEPATH += $$PWD/../PinDll
DEPENDPATH += $$PWD/../PinDll
