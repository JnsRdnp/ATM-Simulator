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

    void eliminateMenu();
    void generalMenuListHandler(QListWidgetItem*);


    void JWThandler(QByteArray);
    void timerResetHandler();
    void timedSignout();

signals:
    void menuTimerRestartSignal();

private:
    Ui::MainWindow *ui;

    balanceDialog *pBalanceDialog;
    accountDialog *pAccountDialog;
    withdrawdll *pWithdraw;
    SignoutTimerInterface *signoutTimer;
    QTimer *timer;
    QTimer *Timer;
    int timeout = 10000;


};
#endif // MAINWINDOW_H
