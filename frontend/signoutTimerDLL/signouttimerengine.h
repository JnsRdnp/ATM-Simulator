#ifndef SIGNOUTTIMERENGINE_H
#define SIGNOUTTIMERENGINE_H

#include <QObject>
#include <QDialog>
#include <QDebug>
#include <QTimer>

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
    void destroyMenu();
    void login();
    void getNewJsonWebToken();
    QTimer *logoutTimer;

};

#endif // SIGNOUTTIMERENGINE_H
