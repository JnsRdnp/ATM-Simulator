#include "signouttimerengine.h"


SignoutTimerEngine::SignoutTimerEngine(QWidget *parent) :
    QDialog(parent)
{

}

void SignoutTimerEngine::continueSession()
{
    emit menuTimerRestart();
}

void SignoutTimerEngine::destroyMenu()
{
    //login->open();
    emit eliminateMenu();
}

void SignoutTimerEngine::openLogin()
{
    //login->open();
}

void SignoutTimerEngine::getNewJsonWebToken()
{
    qDebug()<<"emit new json web token";
}
