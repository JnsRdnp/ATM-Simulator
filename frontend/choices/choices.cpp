#include "choices.h"

Choices::Choices(QWidget *parent, QString inPIN, QString inCardID, QByteArray inJWT) :
    QDialog(parent)
{
    PIN = inPIN;
    cardID = inCardID;
    JWT = inJWT;

    //networking code
    QString site_url="http://localhost:3000/cards/" + cardID;
    QNetworkRequest cardRequest((site_url));
    QByteArray myJWToken="Bearer "+ JWT;
    cardRequest.setRawHeader(QByteArray("Authorization"),(myJWToken));
    cardGetManager = new QNetworkAccessManager(this);

    connect(cardGetManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getCardInfo(QNetworkReply*)));

    cardReply = cardGetManager->get(cardRequest);
}

void Choices::getCardInfo(QNetworkReply *cardReply)
{
    //original source: https://peatutor.com/qt/http_get.php, refactored by Saku Roininen
    cardResponseData=cardReply->readAll();
    qDebug()<<"DATA : "+cardResponseData;
    QString responseString = QString(cardResponseData);

    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseString.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();

    cardIsCreditOrDebit(jsonObject["credit"].toInt(), jsonObject["debit"].toInt());

    cardReply->deleteLater();
    cardGetManager->deleteLater();

}

void Choices::getAccInfo(QNetworkReply *accReply)
{
    //original source: https://peatutor.com/qt/http_get.php, refactored by Saku Roininen
    accResponseData=accReply->readAll();
    qDebug()<<"DATA : "+accResponseData;

    QJsonDocument jsonResponse = QJsonDocument::fromJson(accResponseData);
    QJsonArray jsonArray = jsonResponse.array();
    qDebug()<<jsonArray;

    accReply->deleteLater();
    accGetManager->deleteLater();
}

void Choices::cardChoiceHandler(QString buttonName)
{
    //checks the buttons name and frees the objects memory
    if (buttonName == "CreditButton"){
        isCardCredit = true;
    } else {
        isCardCredit = false;
    }
    disconnect(cardChoice, SIGNAL(cardChoice(QString)),
               this, SLOT(cardChoiceHandler(QString)));
    delete cardChoice;
    cardChoice = nullptr;
}

void Choices::okClickHandler()
{
    //emit destroyChoices();
    disconnect(errorHandler, SIGNAL(okClickedSignal()),
                         this, SLOT(okClickHandler()));
    delete errorHandler;
    errorHandler = nullptr;
}

void Choices::cardIsCreditOrDebit(int credit, int debit)
{
    if(credit == 1 && debit == 1)
    {
        qDebug()<<"Luodaan käyttäjälle valikko";

        //Creates UI for the user to choose their card type
        cardChoice = new CardChoice(this);
        cardChoice->open();
        connect(cardChoice, SIGNAL(cardChoice(QString)),
                this, SLOT(cardChoiceHandler(QString)));

    } else if (credit == 0 && debit == 1){
        qDebug()<<"Asetetaan käyttäjälle suoraan debit";
        isCardCredit = false;
    } else if (credit == 1 && debit == 0){
        qDebug()<<"Asetetaan käyttäjälle suoraan credit";
        isCardCredit = true;
    } else {
        qDebug()<<"Jotain on mennyt väärin";
        errorHandler = new ErrorScreen(this);
        errorHandler->open();
        connect(errorHandler, SIGNAL(okClickedSignal()),
                this, SLOT(okClickHandler()));
    }
    qDebug()<<"Ollaan tääl";
    startAccountGet();

}

void Choices::startAccountGet()
{
    QString site_url="http://localhost:3000/accounts/card/" + cardID;
    qDebug()<<"Ollaan tääl";
    QNetworkRequest accRequest((site_url));
    qDebug()<<"Ollaan tääl";
    QByteArray myJWToken="Bearer "+ JWT;
    qDebug()<<"Ollaan tääl";
    accRequest.setRawHeader(QByteArray("Authorization"),(myJWToken));
    qDebug()<<"Ollaan tääl";
    accGetManager = new QNetworkAccessManager(this);
    qDebug()<<"Ollaan tääl";

    connect(accGetManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getAccInfo(QNetworkReply*)));
    qDebug()<<"Ollaan tääl";
    accReply = accGetManager->get(accRequest);
    qDebug()<<"Ollaan tääl";
}


