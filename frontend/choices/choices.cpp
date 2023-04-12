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
    //response_data=reply->readAll();
    //qDebug()<<"DATA : "+response_data;

    QString test = "{\"bookHeavyInfo\":{\"Qty\":100},\"bookLightInfo\":{\"Qty\":2}}";

    //QJsonDocument jsonResponse = QJsonDocument::fromJson(test.toUtf8());
    //QJsonObject jsonObject = jsonResponse.object();
    //QJsonObject bookHeavyInfo = jsonObject["bookHeavyInfo"].toObject();
    //int qty = bookHeavyInfo["Qty"].toInt();
    //QJsonObject = jsonObject["credit"].toObject();
    //QJsonArray card = jsonCredit["data"].toArray();
    //qDebug()<< qty;
    //bool credit = card[0].toBool();
    /*if(card[0]==1)
    {
        qDebug()<<"Toimii";
    }
    else
    {
        qDebug()<<"Ei Toimi";
    }for (int i = 0; i < json_array.size(); i++)
    {
        QJsonObject object = json_array[i].toObject();

    }*/
    //qDebug() << card;
    reply->deleteLater();
    getManager->deleteLater();
}
