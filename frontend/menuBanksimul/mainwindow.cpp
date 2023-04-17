#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "saldoui.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->saldo,SIGNAL(clicked(bool)),
                this, SLOT(saldoClickHandler()));

    pSaldoUI = new saldoUI(this);

    connect(ui->nosto,SIGNAL(clicked(bool)),
                this, SLOT(nostoClickHandler()));

    pnostoUI = new nostoUI(this);

    connect(ui->tili,SIGNAL(clicked(bool)),
                this, SLOT(tiliClickHandler()));

    ptiliUI = new tiliUI(this);

    connect(ui->kirjauduUlos,SIGNAL(clicked(bool)),
                this, SLOT(kirjauduUloshandler()));


    //main menu timer;
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(timedSignout()));
    Timer->start(timeout);

    connect(this,SIGNAL(menuTimerRestartSignal()),this,SLOT(menuTimerRestart()));

}

MainWindow::~MainWindow()
{
    delete pBalanceDialog;
    pBalanceDialog = nullptr;

    delete pAccountDialog;
    pAccountDialog = nullptr;

    delete pWithdraw;
    pWithdraw = nullptr;

    delete timer;
    timer = nullptr;

    delete ui;

}

void MainWindow::saldoClickHandler()
{
    //second parameter is the accountID
    pBalanceDialog = new balanceDialog(this,2);
    pBalanceDialog->show();
    emit menuTimerRestartSignal();
}

void MainWindow::nostoClickHandler()
{
    pWithdraw = new withdrawdll(this,2,true);
    pWithdraw->open();
    emit menuTimerRestartSignal();
}

void MainWindow::tiliClickHandler()
{
    pAccountDialog = new accountDialog(this,2);
    pAccountDialog->open();
    emit menuTimerRestartSignal();
}

void MainWindow::kirjauduUloshandler()
{
    //login->open();
    this->close();
}

void MainWindow::menuTimerRestart()
{
    qDebug()<<"menutimer restart \r";
    Timer->start(timeout);
}

void MainWindow::JWThandler(QByteArray jwt)
{
    qDebug()<<jwt;
    //this->close();
    qDebug()<<"Time is up";
}

void MainWindow::timerResetHandler()
{
    qDebug() << "timer before " << timer->remainingTime();
    timer->start();         //timer restarts
    qDebug() << "timer after " << timer->remainingTime();
}

void MainWindow::timedSignout()
{
    //timed signout
    signoutTimer = SignoutTimerInterface::getInstance(this);
    timer = new QTimer(this);

    connect(signoutTimer, SIGNAL(newJsonWebToken(QByteArray)),
            this, SLOT(JWThandler(QByteArray)));

    connect(signoutTimer, SIGNAL(menuTimerRestart()),
            this, SLOT(timerResetHandler()));

    timer->start(10000);
    signoutTimer->open();
}



