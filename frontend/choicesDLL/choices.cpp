#include "choices.h"

Choices::Choices(QWidget *parent, QString inPIN, QString inCardID, QString IN_BASE_URL, QByteArray inJWT) :
    QDialog(parent)
{
    PIN = inPIN;
    cardID = inCardID;
    BASE_URL = IN_BASE_URL;
    JWT = inJWT;
    //networking code
    QString site_url= BASE_URL + "cards/" + cardID;
    QNetworkRequest cardRequest((site_url));
    QByteArray myJWToken="Bearer "+ JWT;
    cardRequest.setRawHeader(QByteArray("Authorization"),(myJWToken));
    cardGetManager = new QNetworkAccessManager(this);

    connect(cardGetManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getCardInfo(QNetworkReply*)));

    cardReply = cardGetManager->get(cardRequest);
}

Choices::~Choices()
{
    disconnect(cardChoice, SIGNAL(cardChoice(QString)),
               this, SLOT(cardChoiceHandler(QString)));
    delete cardChoice;
    cardChoice = nullptr;

    disconnect(errorHandler, SIGNAL(okClickedSignal()),
                         this, SLOT(okClickHandler()));
    delete errorHandler;
    errorHandler = nullptr;

    disconnect(accountChoice, SIGNAL(selectedAccountSender(QString)),
            this, SLOT(selectedAccountHandler(QString)));
    accountChoice -> close();
    delete accountChoice;
    accountChoice = nullptr;
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
    //checks the buttons name and closes the objects ui
    if (buttonName == "CreditButton"){
        isCardCredit = true;
    } else {
        isCardCredit = false;
    }
    this->cardChoice->close();
}

void Choices::startAccountGet()
{
    QString site_url= BASE_URL + "accounts/card/" + cardID;
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
    //sets the fetched item name as Account ID
    accountID = accID.toInt();
    this->accountChoice->close();
    createMainMenu();
}

void Choices::jsonError()
{
    qDebug()<<"Something has gone wrong";
    noErrors = false;
    errorHandler = new ErrorScreen(this);
    errorHandler->open();
    connect(errorHandler, SIGNAL(okClickedSignal()),
            this, SLOT(okClickHandler()));
}

void Choices::createMainMenu()
{
    qDebug() << "create the main menu";
    qDebug() << PIN << cardID << isCardCredit << accountID << BASE_URL << JWT;
    mainWindow = new Menu(this, PIN, cardID, isCardCredit, accountID, BASE_URL, JWT);

    mainWindow->setWindowState(Qt::WindowFullScreen);

    qDebug() << "aukaistaan ikkuna";
    mainWindow->open();
    //PIN, cardID, JWT, isCardCredit, accountID)
}

void Choices::okClickHandler()
{
    this->cardChoice->close();
}

