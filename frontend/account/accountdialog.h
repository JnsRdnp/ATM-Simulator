#ifndef ACCOUNTDIALOG_H
#define ACCOUNTDIALOG_H

#include "account_global.h"
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDebug>

namespace Ui {
class accountDialog;
}

class ACCOUNT_EXPORT accountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit accountDialog(QWidget *parent = nullptr,int id=0);
    ~accountDialog();


private:
    Ui::accountDialog *ui;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;


    void historyNetwork(int);
    int accountID;
    QString page;

    int stringIndex;

private slots:
    void getHistorySlot (QNetworkReply *reply);
    void backHandler();
    void pageChange();
signals:
    void localRestartTimerSignal();
};

#endif // ACCOUNTDIALOG_H
