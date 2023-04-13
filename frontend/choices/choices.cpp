#include "choices.h"

Choices::Choices(QWidget *parent, QString inPIN, QString inCardID, QByteArray inJWT) :
    QDialog(parent)
{
    PIN = inPIN;
    cardID = inCardID;
    JWT = inJWT;

    //networking code
    QString site_url="http://localhost:3000/cards/" + cardID;
    QNetworkRequest request((site_url));
    QByteArray myJWToken="Bearer "+ JWT;
    request.setRawHeader(QByteArray("Authorization"),(myJWToken));
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getCardInfo(QNetworkReply*)));

    reply = getManager->get(request);
}

void Choices::getCardInfo(QNetworkReply *reply)
{
    //original source: https://peatutor.com/qt/http_get.php, refactored by Saku Roininen
    responseData=reply->readAll();
    qDebug()<<"DATA : "+responseData;
    QString responseString = QString(responseData);

    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseString.toUtf8());
     qDebug() << jsonResponse.isEmpty();
    QJsonObject jsonObject = jsonResponse.object();
    qDebug() << jsonObject.isEmpty();
    int credit = jsonObject["credit"].toInt();
    int debit = jsonObject["debit"].toInt();
    qDebug() << credit;
    qDebug() << debit;


    if(credit == 1 && debit == 1)
    {
        qDebug()<<"Luodaan käyttäjälle valikko";
        //luo käyttöliittymä, jossa käyttäjä valitsee kortti-tyypin
        CardChoice *cardChoice = new CardChoice(this);
        cardChoice->open();
    } else if (credit == 0 && debit == 1){
        qDebug()<<"Asetetaan käyttäjälle suoraan debit";
        isCardCredit = false;
    } else if (credit == 1 && debit == 0){
        qDebug()<<"Asetetaan käyttäjälle suoraan credit";
        isCardCredit = true;
    } else {
        qDebug()<<"Jotain on mennyt väärin";
        //emit cardIsErrorSignal
    }



    reply->deleteLater();
    getManager->deleteLater();
}
