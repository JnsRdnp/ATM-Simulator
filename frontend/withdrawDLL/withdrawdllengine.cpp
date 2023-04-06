#include "withdrawdllengine.h"

WithdrawDLLEngine::WithdrawDLLEngine(QWidget *parent, int inAccountID, bool inIsCardCredit, QByteArray inJwt) : QDialog(parent)
{
    qDebug() << "Create DLL Engine";
    accountID = inAccountID;
    isCardCredit = inIsCardCredit;
    jwt = inJwt;
}


WithdrawDLLEngine::~WithdrawDLLEngine()
{
    qDebug() << "Destroy DLL Engine";
}

void WithdrawDLLEngine::withdraw(float num)
{
    //Original source: https://peatutor.com/qt/http_put.php, edited by Saku Roininen
    qDebug() << "Engine Withdraw method";
    const QString SERVER_URL = "http://localhost:3000/";

    QJsonObject withdrawObj;
    withdrawObj.insert("accountID",accountID);
    withdrawObj.insert("amount", num);

    QString site_url = "";

    if (isCardCredit == true){
       site_url = SERVER_URL + "accounts/creditWithdraw";
    } else {
       site_url = SERVER_URL + "accounts/debitWithdraw";
    }

    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray myToken="Bearer " + jwt;
    request.setRawHeader(QByteArray("Authorization"),(myToken));

    putManager = new QNetworkAccessManager(this);
    connect(putManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(withdrawMoney(QNetworkReply*)));

    reply = putManager->put(request, QJsonDocument(withdrawObj).toJson());
    disconnect(putManager);
}

void WithdrawDLLEngine::withdrawMoney(QNetworkReply *reply)
{
    //Original source: https://peatutor.com/qt/http_put.php
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    putManager->deleteLater();
}
