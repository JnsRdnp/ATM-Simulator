#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "saldoui.h"
#include "nostoui.h"
#include "tiliui.h"
#include "kirjauduulosui.h"
#include <QMainWindow>
#include "balancedialog.h"
#include "accountdialog.h"
#include "withdrawdll.h"
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

signals:
    void menuTimerRestartSignal();

private:
    Ui::MainWindow *ui;
    saldoUI * pSaldoUI;
    nostoUI * pnostoUI;
    tiliUI * ptiliUI;
    balanceDialog *pBalanceDialog;
    accountDialog *pAccountDialog;
    withdrawdll *pWithdraw;

    QTimer *Timer;
    int timeout = 5000;


};
#endif // MAINWINDOW_H
