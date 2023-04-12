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
    getNewJsonWebToken();
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
    qDebug() << "Get New JWT method";
    const QString SERVER_URL = "http://localhost:3000/";

    QJsonObject jsonObj;
    jsonObj.insert("cardID","3");
    jsonObj.insert("PINcode","2345");

    QString site_url = SERVER_URL + "login";
    QByteArray jwt = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJjYXJkSUQiOiIxMjM0IiwiaWF0IjoxNjgxMzIyODA0LCJleHAiOjE2ODEzMjMwMDR9.ZURjd2oWKSCo-LP0nfl4FZz3kfl2pumlql2hXKi0bv0";

    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray myToken="Bearer " + jwt;
    request.setRawHeader(QByteArray("Authorization"),(myToken));

    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(renewToken(QNetworkReply*)));

    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());
}

void SignoutTimerEngine::renewToken(QNetworkReply *reply)
{
    qDebug()<<"Renew Token";
    responseData = reply->readAll();
    qDebug()<<responseData;
    reply->deleteLater();
    postManager->deleteLater();

    //These emits would trigger before postManager could send a signal and are thus here
    emit menuTimerRestart();
    emit closeSignout();
}


