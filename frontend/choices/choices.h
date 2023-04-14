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
    void selectedAccountHandler(QString accID);
    void okClickHandler();

private:
    QString PIN = "";
    QString cardID = "";
    QByteArray JWT = "";

    CardChoice *cardChoice;
    ErrorScreen *errorHandler;
    AccountChoice *accountChoice;
    //MainWindow *mainWindow;
    bool noErrors = true;
    bool isCardCredit;
    int accountID;

    //for getting card info
    QNetworkAccessManager *cardGetManager;
    QNetworkReply *cardReply;
    QByteArray cardResponseData;

    //for logic of dealing with the card info
    void cardIsCreditOrDebit(int, int);
    void getCardsAccounts();

    //for getting account info
    QNetworkAccessManager *accGetManager;
    QNetworkReply *accReply;
    QByteArray accResponseData;

    //for logic of dealing with the account info
    void startAccountGet();

    //error handling
    void jsonError();

    void createMainMenu();
};

#endif // CHOICES_H
