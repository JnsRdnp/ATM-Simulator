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

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getCardInfo(QNetworkReply*)));

    reply = getManager->get(request);
}

void Choices::getCardInfo(QNetworkReply *reply)
{
    //original source: https://peatutor.com/qt/http_get.php, refactored by Saku Roininen
    responseData=reply->readAll();
    qDebug()<<"DATA : "+responseData;
    QString responseString = QString(responseData);

    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseString.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();

    cardIsCreditOrDebit(jsonObject["credit"].toInt(), jsonObject["debit"].toInt());

    reply->deleteLater();
    getManager->deleteLater();
}

void Choices::cardChoiceHandler(QString buttonName)
{
    //checks the buttons name and frees the objects memory
    if (buttonName == "CreditButton"){
        isCardCredit = true;
    } else {
        isCardCredit = false;
    }
    delete cardChoice;
    cardChoice = nullptr;
    disconnect(cardChoice, SIGNAL(cardChoice(QString)),
               this, SLOT(cardChoiceHandler(QString)));
}

void Choices::okClickHandler()
{
    //emit destroyChoices();
    delete errorHandler;
    errorHandler = nullptr;
    disconnect(errorHandler, SIGNAL(okClickedSignal()),
                         this, SLOT(okClickHandler()));
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

}
