QT       += core gui
QT +=network
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    nostoui.cpp \
    saldoui.cpp \
    tiliui.cpp

HEADERS += \
    mainwindow.h \
    nostoui.h \
    saldoui.h \
    tiliui.h

FORMS += \
    mainwindow.ui \
    nostoui.ui \
    saldoui.ui \
    tiliui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target






#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../accountDLL/build/release/ -laccountDLL
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../accountDLL/build/debug/ -laccountDLL
#else:unix:!macx: LIBS += -L$$PWD/../accountDLL/build/ -laccountDLL

#INCLUDEPATH += $$PWD/../accountDLL
#DEPENDPATH += $$PWD/../accountDLL

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../balance/build/release/ -lbalance
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../balance/build/debug/ -lbalance
else:unix:!macx: LIBS += -L$$PWD/../balance/build/ -lbalance

INCLUDEPATH += $$PWD/../balance
DEPENDPATH += $$PWD/../balance

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../account/build/release/ -laccount
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../account/build/debug/ -laccount
else:unix:!macx: LIBS += -L$$PWD/../account/build/ -laccount

INCLUDEPATH += $$PWD/../account
DEPENDPATH += $$PWD/../account
