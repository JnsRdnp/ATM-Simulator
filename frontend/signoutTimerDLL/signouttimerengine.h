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
    SignoutTimerEngine(QWidget *parent = nullptr);
    ~SignoutTimerEngine();
    void continueSession();
    void destroyMenuCaller();
signals:
    void menuTimerRestart();
    void newJsonWebToken(QByteArray);
    void eliminateMenu();
    void closeSignout();
public slots:
    void signalDestroyMenuCaller();
private:
    QNetworkAccessManager *postmanager;
    QNetworkReply *reply;
    QByteArray responseData;
    void destroyMenu();
    void login();
    void getNewJsonWebToken();
    QTimer *logoutTimer;
private slots:
    void renewToken(QNetworkReply *reply);
    void token();
};

#endif // SIGNOUTTIMERENGINE_H
