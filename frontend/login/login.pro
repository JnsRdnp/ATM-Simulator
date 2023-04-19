QT += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    environment.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    environment.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../pincodeDLL/build/release/ -lpincodedll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../pincodeDLL/build/debug/ -lpincodedll
else:unix: LIBS += -L$$PWD/../pincodeDLL/build/ -lpincodedll

INCLUDEPATH += $$PWD/../pincodedll
DEPENDPATH += $$PWD/../pincodedll

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../CardReaderDLL/build/release/ -lCardReader
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../CardReaderDLL/build/debug/ -lCardReader
else:unix: LIBS += -L$$PWD/../CardReaderDLL/build/ -lCardReader

INCLUDEPATH += $$PWD/../CardReaderDLL
DEPENDPATH += $$PWD/../CardReaderDLL

unix:!macx: LIBS += -L$$PWD/../choicesDLL/build/ -lchoices

INCLUDEPATH += $$PWD/../choicesDLL
DEPENDPATH += $$PWD/../choicesDLL

unix:!macx|win32: LIBS += -L$$PWD/../withdrawDLL/build/ -lwithdrawDLL

INCLUDEPATH += $$PWD/../withdrawDLL
DEPENDPATH += $$PWD/../withdrawDLL

unix:!macx|win32: LIBS += -L$$PWD/../signoutTimerDLL/build/ -lsignoutTimerDLL

INCLUDEPATH += $$PWD/../signoutTimerDLL
DEPENDPATH += $$PWD/../signoutTimerDLL

unix:!macx|win32: LIBS += -L$$PWD/../menuDLL/build/ -lmenu

INCLUDEPATH += $$PWD/../menuDLL
DEPENDPATH += $$PWD/../menuDLL

unix:!macx|win32: LIBS += -L$$PWD/../balanceDLL/build/ -lbalance

INCLUDEPATH += $$PWD/../balanceDLL
DEPENDPATH += $$PWD/../balanceDLL

unix:!macx|win32: LIBS += -L$$PWD/../accountDLL/build/ -laccount

INCLUDEPATH += $$PWD/../accountDLL
DEPENDPATH += $$PWD/../accountDLL

unix:!macx|win32: LIBS += -L$$PWD/../withdrawDLL/build/ -lwithdrawDLL

INCLUDEPATH += $$PWD/../withdrawDLL
DEPENDPATH += $$PWD/../withdrawDLL

unix:!macx|win32: LIBS += -L$$PWD/../choicesDLL/build/ -lchoices

INCLUDEPATH += $$PWD/../choicesDLL
DEPENDPATH += $$PWD/../choicesDLL
