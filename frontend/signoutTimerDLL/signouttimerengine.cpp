#include "signouttimerengine.h"

SignoutTimerEngine::SignoutTimerEngine(QWidget *parent, QString inCardID, QString inPIN, QString IN_BASE_URL) :
    QDialog(parent)
{
    cardID = inCardID;
    PIN = inPIN;
    BASE_URL = IN_BASE_URL;
    logoutTimer = new QTimer(this);
    logoutTimer->start(10000);
    connect(logoutTimer, &QTimer::timeout, this, &SignoutTimerEngine::destroyMenu);
}

SignoutTimerEngine::~SignoutTimerEngine()
{
    //QTimer is deleted and freed with it's parent, nothing is needed here
}

void SignoutTimerEngine::continueSession()
{
    qDebug()<<"restarting timer";
    getNewJsonWebToken();
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

    QJsonObject jsonObj;
    jsonObj.insert("cardID",cardID);
    jsonObj.insert("PINcode",PIN);

    QString site_url = BASE_URL + "login";

    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

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
    emit newJsonWebToken(responseData);
    emit menuTimerRestart();
    emit closeSignout();
}


