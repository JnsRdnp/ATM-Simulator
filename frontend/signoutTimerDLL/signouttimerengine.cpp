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

void SignoutTimerEngine::token()
{
    QJsonObject jsonObj;

    jsonObj.insert("cardID","1");
    jsonObj.insert("PINcode","2345");

    QString site_url="http://localhost:3001/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QByteArray myToken="Bearer xRstgr...";
    request.setRawHeader(QByteArray("Authorization"),(myToken));

    postmanager = new QNetworkAccessManager(this);
    connect(postmanager, SIGNAL(finished (QNetworkReply*)), this, SLOT(renewToken(QNetworkReply*)));

    reply = postmanager->post(request, QJsonDocument(jsonObj).toJson());
}

void SignoutTimerEngine::renewToken(QNetworkReply *reply)
{
    responseData = reply->readAll();
    qDebug()<<responseData;
    reply->deleteLater();
    postmanager->deleteLater();
}


