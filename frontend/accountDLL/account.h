#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "accountDLL_global.h"

namespace Ui {
class account;
}

class ACCOUNTDLL_EXPORT account : public QDialog
{
    Q_OBJECT

public:
    explicit account(QWidget *parent = nullptr);
    ~account();

private:
    Ui::account *ui;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    void accountOpen();

private slots:
    void getBalanceSlot (QNetworkReply *reply);
    void getHistorySlot (QNetworkReply *reply);
};

#endif // ACCOUNT_H
