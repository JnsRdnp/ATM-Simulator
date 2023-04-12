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
    QJsonObject jsonObj;
    jsonObj.insert("cardID","3");
    jsonObj.insert("PINcode","2345");

    QString site_url="http://localhost:3001/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    QByteArray jwt = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJjYXJkSUQiOiIzIiwiaWF0IjoxNjgxMjk4NjQwLCJleHAiOjE2ODEyOTg4NDB9.JYkk4ZGs2oJu4cTR238iTyNrSiuTANYjtEOqUwgprzA";
    QByteArray myToken="Bearer " +jwt;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    postManager = new QNetworkAccessManager(this);
    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());
    connect(postManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(renewToken(QNetworkReply*)), Qt::QueuedConnection);
}

void SignoutTimerEngine::renewToken(QNetworkReply *reply)
{
    qDebug()<<"Vittu saatana";
    responseData = reply->readAll();
    qDebug()<<responseData;
    reply->deleteLater();
    postManager->deleteLater();
}


