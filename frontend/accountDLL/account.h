#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "accountDLL_global.h"
#include <QDebug>

namespace Ui {
class account;
}

class ACCOUNTDLL_EXPORT account : public QDialog
{
    Q_OBJECT

public:
    explicit account(QWidget *parent = nullptr,int id=0);
    ~account();

private:
    Ui::account *ui;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    void accountOpen();
    int accountID;

private slots:
    void getBalanceSlot (QNetworkReply *reply);
};

#endif // ACCOUNT_H
