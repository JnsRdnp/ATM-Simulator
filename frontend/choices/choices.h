#ifndef CHOICES_H
#define CHOICES_H

#include "choices_global.h"
#include "cardchoice.h"
#include "errorscreen.h"
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
    void cardChoiceHandler(QString buttonName);
    void okClickHandler();

private:
    QString PIN = "";
    QString cardID = "";
    QByteArray JWT = "";

    CardChoice *cardChoice;
    ErrorScreen *errorHandler;
    bool isCardCredit;

    //for networking and getting card info
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray responseData;

    //for logic of dealing with the card info
    void cardIsCreditOrDebit(int, int);
};

#endif // CHOICES_H
