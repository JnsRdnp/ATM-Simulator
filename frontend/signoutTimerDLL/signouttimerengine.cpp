#include "signouttimerengine.h"


SignoutTimerEngine::SignoutTimerEngine(QWidget *parent) :
    QDialog(parent)
{
    logoutTimer = new QTimer(this);
    connect(logoutTimer, &QTimer::timeout, this, &SignoutTimerEngine::destroyMenuCaller);
    logoutTimer->start(10000);
}

void SignoutTimerEngine::continueSession()
{
    emit menuTimerRestart();
    getNewJsonWebToken();
}

void SignoutTimerEngine::destroyMenuCaller()
{
    destroyMenu();
}

void SignoutTimerEngine::destroyMenu()
{
    //login->open();
    emit eliminateMenu();

}

void SignoutTimerEngine::login()
{
    //login->open();
}

void SignoutTimerEngine::getNewJsonWebToken()
{
    qDebug()<<"emit new json web token";
    emit newJsonWebToken("1234");
}
