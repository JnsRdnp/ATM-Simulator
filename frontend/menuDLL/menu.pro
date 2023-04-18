QT       += core gui
QT +=network
QT += widgets

TEMPLATE = lib
DEFINES += MENU_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    menu.cpp

HEADERS += \
    menu_global.h \
    menu.h


FORMS += \
    menu.ui

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target





win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../accountDLL/build/release/ -laccount
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../accountDLL/build/debug/ -laccount
else:unix:!macx: LIBS += -L$$PWD/../accountDLL/build/ -laccount

INCLUDEPATH += $$PWD/../accountDLL
DEPENDPATH += $$PWD/../accountDLL

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../balanceDLL/build/release/ -lbalance
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../balanceDLL/build/debug/ -lbalance
else:unix:!macx: LIBS += -L$$PWD/../balanceDLL/build/ -lbalance

INCLUDEPATH += $$PWD/../balanceDLL
DEPENDPATH += $$PWD/../balanceDLL

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../withdrawDLL/build/release/ -lwithdrawDLL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../withdrawDLL/build/debug/ -lwithdrawDLL
else:unix:!macx: LIBS += -L$$PWD/../withdrawDLL/build/ -lwithdrawDLL

INCLUDEPATH += $$PWD/../withdrawDLL
DEPENDPATH += $$PWD/../withdrawDLL

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../signoutTimerDLL/build/release/ -lsignoutTimerDLL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../signoutTimerDLL/build/debug/ -lsignoutTimerDLL
else:unix:!macx: LIBS += -L$$PWD/../signoutTimerDLL/build/ -lsignoutTimerDLL

INCLUDEPATH += $$PWD/../signoutTimerDLL
DEPENDPATH += $$PWD/../signoutTimerDLL

unix:!macx: LIBS += -L$$PWD/../signoutTimerDLL/build/ -lsignoutTimerDLL

INCLUDEPATH += $$PWD/../signoutTimerDLL
DEPENDPATH += $$PWD/../signoutTimerDLL
