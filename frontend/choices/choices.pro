QT += core gui
QT +=network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
DEFINES += CHOICES_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accountchoice.cpp \
    cardchoice.cpp \
    choices.cpp \
    errorscreen.cpp

HEADERS += \
    accountchoice.h \
    cardchoice.h \
    choices_global.h \
    choices.h \
    errorscreen.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    accountchoice.ui \
    cardchoice.ui \
    errorscreen.ui
