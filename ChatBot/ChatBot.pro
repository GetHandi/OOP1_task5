QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    foo.cpp \
    globals.cpp \
    main.cpp \
    loginwindow.cpp \
    mainwindow.cpp \
    message.cpp \
    signinwindow.cpp \
    user.cpp

HEADERS += \
    loginwindow.h \
    mainwindow.h \
    message.h \
    signinwindow.h \
    user.h

FORMS += \
    loginwindow.ui \
    mainwindow.ui \
    signinwindow.ui

#INCLUDEPATH += "D:\GetHandi\hobby\qt\OOP1_task5\ChatBot"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
