#ifndef SIGNOUTTIMERENGINE_H
#define SIGNOUTTIMERENGINE_H

#include <QObject>
#include <QDialog>
#include <QDebug>

class SignoutTimerEngine: public QDialog
{
    Q_OBJECT
public:
    SignoutTimerEngine(QWidget *parent = nullptr);
    void continueSession();
signals:
    void menuTimerRestart();
    void newJsonWebToken(QByteArray);
    void eliminateMenu();
private:
    void destroyMenu();
    void openLogin();
    void getNewJsonWebToken();


};

#endif // SIGNOUTTIMERENGINE_H
