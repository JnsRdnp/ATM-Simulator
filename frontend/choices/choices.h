#ifndef CHOICES_H
#define CHOICES_H

#include "choices_global.h"
#include "cardchoice.h"
#include "errorscreen.h"
#include "accountchoice.h"
#include "QDialog"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class CHOICES_EXPORT Choices : public QDialog
{
    Q_OBJECT
public:
    Choices(QWidget *parent = nullptr, QString inPIN = "", QString inCardID = "", QByteArray inJWT = "");

private slots:
    void getCardInfo (QNetworkReply *reply);
    void getAccInfo (QNetworkReply *reply);
    void cardChoiceHandler(QString buttonName);
    void okClickHandler();

private:
    QString PIN = "";
    QString cardID = "";
    QByteArray JWT = "";

    CardChoice *cardChoice;
    ErrorScreen *errorHandler;
    AccountChoice *accountChoice;

    bool isCardCredit;
    int accountID;

    //for getting card info
    QNetworkAccessManager *cardGetManager;
    QNetworkReply *cardReply;
    QByteArray cardResponseData;

    //for getting account info
    QNetworkAccessManager *accGetManager;
    QNetworkReply *accReply;
    QByteArray accResponseData;

    //for logic of dealing with the card info
    void cardIsCreditOrDebit(int, int);
    void getCardsAccounts();
    void startAccountGet();

    //error handling
    void jsonError();
};

#endif // CHOICES_H
