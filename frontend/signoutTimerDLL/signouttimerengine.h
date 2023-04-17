#ifndef SIGNOUTTIMERENGINE_H
#define SIGNOUTTIMERENGINE_H

#include <QObject>
#include <QDialog>
#include <QDebug>
#include <QTimer>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class SignoutTimerEngine: public QDialog
{
    Q_OBJECT
public:
    SignoutTimerEngine(QWidget *parent = nullptr, QString inCardID = "", QString inPIN = "", QString IN_BASE_URL = "");
    ~SignoutTimerEngine();
    void continueSession();
    QString cardID;
    QString PIN;
    QString BASE_URL;

signals:
    void menuTimerRestart();
    void newJsonWebToken(QByteArray);
    void eliminateMenu();
    void closeSignout();

public slots:
    void destroyMenu();
    void renewToken(QNetworkReply *reply);

private:
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray responseData;

    void login();
    void getNewJsonWebToken();
    QTimer *logoutTimer;

};

#endif // SIGNOUTTIMERENGINE_H
