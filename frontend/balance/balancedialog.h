#ifndef BALANCEDIALOG_H
#define BALANCEDIALOG_H

#include "balance_global.h"
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDebug>

namespace Ui {
class balanceDialog;
}

class BALANCE_EXPORT balanceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit balanceDialog(QWidget *parent = nullptr, int id=0);
    ~balanceDialog();


private:
    Ui::balanceDialog *ui;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    void balanceNetwork();
    int accountID;

private slots:
    void getBalanceSlot (QNetworkReply *reply);
    void backHandler();
};

#endif // BALANCEDIALOG_H
