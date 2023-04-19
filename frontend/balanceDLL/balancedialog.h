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
    explicit balanceDialog(QWidget *parent = nullptr, int id=0,QString inBaseUrl="",QByteArray inJwt = "");
    ~balanceDialog();


private:
    Ui::balanceDialog *ui;
    QNetworkAccessManager *getManager;
    QNetworkReply *balanceReply;
    QByteArray response_data;

    void balanceNetwork();
    int accountID;

    QNetworkReply *historyReply;
    void historyNetwork();

    int stringIndex=0;

    QByteArray jwt;
    QString baseUrl;

    void scalingUI();

private slots:
    void backHandler();

    void getBalanceSlot (QNetworkReply *balanceReply);

    void getHistorySlot(QNetworkReply *historyReply);

signals:
    void localRestartTimerSignal();

};

#endif // BALANCEDIALOG_H
