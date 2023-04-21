#include "withdrawdllengine.h"

WithdrawDLLEngine::WithdrawDLLEngine(QWidget *parent, int inAccountID, bool inIsCardCredit,QString inBaseUrl,QByteArray inJwt) : QDialog(parent)
{
//    qDebug() << "Create DLL Engine";
    accountID = inAccountID;
    isCardCredit = inIsCardCredit;
    baseUrl = inBaseUrl;
    jwt = inJwt;
//    qDebug()<<"JWT on"<<jwt;
}


WithdrawDLLEngine::~WithdrawDLLEngine()
{
//    qDebug() << "Destroy DLL Engine";
}

void WithdrawDLLEngine::withdraw(float num)
{
    //Original source: https://peatutor.com/qt/http_put.php, edited by Saku Roininen
//    qDebug() << "Engine Withdraw method";
//    qDebug() << num;

    QJsonObject withdrawObj;
    withdrawObj.insert("accountID",accountID);
    withdrawObj.insert("amount", num);

    QString site_url = "";

    if (isCardCredit == true){
       site_url = baseUrl + "accounts/creditWithdraw";
    } else {
       site_url = baseUrl + "accounts/debitWithdraw";
    }

    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(jwt));

    putManager = new QNetworkAccessManager(this);
    connect(putManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(withdrawMoney(QNetworkReply*)));

    reply = putManager->put(request, QJsonDocument(withdrawObj).toJson());


    disconnect(putManager);

}

void WithdrawDLLEngine::withdrawMoney(QNetworkReply *reply)
{
    //Original source: https://peatutor.com/qt/http_put.php
    responseData=reply->readAll();
//    qDebug()<<responseData;
    //if responseData == "message which we get when fail"
    //emit failWithdraw()
    //else
    //emit successWithdraw()
    reply->deleteLater();
    putManager->deleteLater();

    emit responseReady();

}
