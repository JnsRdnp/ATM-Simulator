#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlistwidget.h"
#include <QMainWindow>
#include "balancedialog.h"
#include "accountdialog.h"
#include "withdrawdll.h"
#include "signouttimerinterface.h"
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void saldoClickHandler();
    void nostoClickHandler();
    void tiliClickHandler();
    void kirjauduUloshandler();
    void menuTimerRestart();

    void generalMenuListHandler(QListWidgetItem*);


    void JWThandler(QByteArray);
    void timerResetHandler();
    void timedSignout();


private:
    Ui::MainWindow *ui;

    balanceDialog *pBalanceDialog;
    accountDialog *pAccountDialog;
    withdrawdll *pWithdraw;
    SignoutTimerInterface *signoutTimer;
    QTimer *timer;
    QTimer *Timer;
    int timeout = 30000;

    QString baseUrl = "http://localhost:3000/";
    QByteArray jwt = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJjYXJkSUQiOiIyMzQ1IiwiaWF0IjoxNjgxNzE2MDIzLCJleHAiOjE2ODE3MTYyMjN9.VqODXtB1U8rIV3TINJgKQEAzLTqmmT246OYWxy0gKlA";


};
#endif // MAINWINDOW_H
