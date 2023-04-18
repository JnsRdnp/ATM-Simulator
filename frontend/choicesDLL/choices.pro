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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../menuDLL/build/release/ -lmenu
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../menuDLL/build/debug/ -lmenu
else:unix:!macx: LIBS += -L$$PWD/../menuDLL/build/ -lmenu

INCLUDEPATH += $$PWD/../menuDLL
DEPENDPATH += $$PWD/../menuDLL

unix:!macx: LIBS += -L$$PWD/../accountDLL/build/ -laccount

INCLUDEPATH += $$PWD/../accountDLL
DEPENDPATH += $$PWD/../accountDLL

unix:!macx: LIBS += -L$$PWD/../balanceDLL/build/ -lbalance

INCLUDEPATH += $$PWD/../balanceDLL
DEPENDPATH += $$PWD/../balanceDLL

unix:!macx: LIBS += -L$$PWD/../menuDLL/build/ -lmenu

INCLUDEPATH += $$PWD/../menuDLL
DEPENDPATH += $$PWD/../menuDLL

unix:!macx: LIBS += -L$$PWD/../signoutTimerDLL/build/ -lsignoutTimerDLL

INCLUDEPATH += $$PWD/../signoutTimerDLL
DEPENDPATH += $$PWD/../signoutTimerDLL

unix:!macx: LIBS += -L$$PWD/../withdrawDLL/build/ -lwithdrawDLL

INCLUDEPATH += $$PWD/../withdrawDLL
DEPENDPATH += $$PWD/../withdrawDLL
