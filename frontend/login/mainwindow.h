#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "pincode.h"
#include "cardreader.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "choices.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void receivePinNumber(QString);
    void on_CardButton_clicked();
    void receiveCardID(QString);
    void on_btnCredentials_clicked();
    void addLoginSlot(QNetworkReply * reply);
    void destroySignalHandler();


private:
    Ui::MainWindow *ui;
    pincode * pPincode;
    Choices * choice;
    CardReader * cardReader;

    void updateUI();
    void checkCredentials();
    QString PINCode;
    QString cardID;
    int attempts;
    void checkNumber();
    QNetworkAccessManager *postManager;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray token;

    void clearLoginData();
};
#endif // MAINWINDOW_H
