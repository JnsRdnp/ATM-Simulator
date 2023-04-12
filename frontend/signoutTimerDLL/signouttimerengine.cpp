#include "signouttimerengine.h"


SignoutTimerEngine::SignoutTimerEngine(QWidget *parent) :
    QDialog(parent)
{
    logoutTimer = new QTimer(this);
    logoutTimer->start(30000);
    connect(logoutTimer, &QTimer::timeout, this, &SignoutTimerEngine::signalDestroyMenuCaller);
}

SignoutTimerEngine::~SignoutTimerEngine()
{

}

void SignoutTimerEngine::continueSession()
{
    qDebug()<<"restarting timer";
    emit menuTimerRestart();
    getNewJsonWebToken();
    emit closeSignout();
}

void SignoutTimerEngine::destroyMenuCaller()
{
    destroyMenu();
}


void SignoutTimerEngine::signalDestroyMenuCaller()
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
