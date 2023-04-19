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
    explicit accountDialog(QWidget *parent = nullptr,int id=0,QString inBaseUrl="",QByteArray inJwt = "");
    ~accountDialog();


private:
    Ui::accountDialog *ui;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;


    void historyNetwork(int);
    int accountID;
    QString page;

    QString baseUrl;
    QByteArray jwt;

    int stringIndex;
    void scalingUI();

private slots:
    void getHistorySlot (QNetworkReply *reply);
    void backHandler();
    void pageChange();

};

#endif // ACCOUNTDIALOG_H
