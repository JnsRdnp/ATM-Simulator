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
    //starts the next network request
    startAccountGet();

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
        jsonError();
    }

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

void Choices::startAccountGet()
{
    QString site_url="http://localhost:3000/accounts/card/" + cardID;
    QNetworkRequest accRequest((site_url));
    QByteArray myJWToken="Bearer "+ JWT;
    accRequest.setRawHeader(QByteArray("Authorization"),(myJWToken));
    accGetManager = new QNetworkAccessManager(this);

    connect(accGetManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getAccInfo(QNetworkReply*)));
    accReply = accGetManager->get(accRequest);
}

void Choices::getAccInfo(QNetworkReply *accReply)
{
    //original source: https://peatutor.com/qt/http_get.php, refactored by Saku Roininen
    accResponseData=accReply->readAll();
    qDebug()<<"DATA : "+accResponseData;

    QJsonDocument jsonAccResponse = QJsonDocument::fromJson(accResponseData);
    QJsonArray jsonAccArray = jsonAccResponse.array();
    QJsonObject jsonAccObject;

    if (!(jsonAccArray.size() > 0)){
        jsonError();
        qDebug()<<"Arrayn koko on 0";
    } else if (jsonAccArray.size() == 1){
        jsonAccObject = jsonAccArray[0].toObject();
        accountID = jsonAccObject["idaccounts"].toInt();
        qDebug()<<"Arrayn koko on 1";
        createMainMenu();
    } else {
        //luo accountchoice menu ja laita käyttäjä valitsemaan.
        accountChoice = new AccountChoice(this);
        connect(accountChoice, SIGNAL(selectedAccountSender(QString)),
                this, SLOT(selectedAccountHandler(QString)));
        accountChoice->setQJsonArray(jsonAccArray);
        accountChoice->show();
        qDebug()<<"Arrayn koko on isompi kuin 1";
    }

    qDebug()<<jsonAccArray;
    accReply->deleteLater();
    accGetManager->deleteLater();
}

void Choices::selectedAccountHandler(QString accID)
{
    accountID = accID.toInt();
    disconnect(accountChoice, SIGNAL(selectedAccountSender(QString)),
            this, SLOT(selectedAccountHandler(QString)));
    delete accountChoice;
    accountChoice = nullptr;
    createMainMenu();
}

void Choices::jsonError()
{
    qDebug()<<"Jotain on mennyt väärin";
    noErrors = false;
    errorHandler = new ErrorScreen(this);
    errorHandler->open();
    connect(errorHandler, SIGNAL(okClickedSignal()),
            this, SLOT(okClickHandler()));
}

void Choices::createMainMenu()
{
    qDebug() << "create the main menu";
    mainWindow = new Menu(this);
    mainWindow->open();
    //PIN, cardID, JWT, isCardCredit, accountID)
}

void Choices::okClickHandler()
{
    this->close();
    disconnect(errorHandler, SIGNAL(okClickedSignal()),
                         this, SLOT(okClickHandler()));
    delete errorHandler;
    errorHandler = nullptr;
}

