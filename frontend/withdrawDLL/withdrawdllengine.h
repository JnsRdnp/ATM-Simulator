#ifndef WITHDRAWDLLENGINE_H
#define WITHDRAWDLLENGINE_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDebug>


class WithdrawDLLEngine : public QDialog
{
    Q_OBJECT
public:
    WithdrawDLLEngine(QWidget *parent = nullptr, int inAccountID = 0, bool inIsCardCredit = false, QByteArray inJwt = "");
    ~WithdrawDLLEngine();
    void withdraw(float);

private slots:
    void withdrawMoney (QNetworkReply *reply);

private:
    int accountID;
    bool isCardCredit;
    QByteArray jwt;
    QNetworkAccessManager *putManager;
    QNetworkReply *reply;
    QByteArray responseData;
};

#endif // WITHDRAWDLLENGINE_H
