#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->listMenu, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(generalMenuListHandler(QListWidgetItem*)));


    //main menu timer;
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(timedSignout()));
    Timer->start(timeout);


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

    delete signoutTimer;
    signoutTimer = nullptr;

    delete ui;

}

void MainWindow::saldoClickHandler()
{
    //second parameter is the accountID
    pBalanceDialog = new balanceDialog(this,2);
    pBalanceDialog->show();

    menuTimerRestart();
}

void MainWindow::nostoClickHandler()
{
    pWithdraw = new withdrawdll(this,2,true);
    pWithdraw->open();

    menuTimerRestart();
}

void MainWindow::tiliClickHandler()
{
    pAccountDialog = new accountDialog(this,2);
    pAccountDialog->open();

    menuTimerRestart();
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


void MainWindow::generalMenuListHandler(QListWidgetItem *item)
{
    if (ui->listMenu->item(0) == item) {
        saldoClickHandler();
    }
    else if (ui->listMenu->item(1) == item){
        nostoClickHandler();
    }
    else if (ui->listMenu->item(2) == item){
        tiliClickHandler();
    }
    else if (ui->listMenu->item(3) == item){
        kirjauduUloshandler();
    }
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
    signoutTimer = new SignoutTimerInterface(this);

    timer = new QTimer(this);

    connect(signoutTimer, SIGNAL(newJsonWebToken(QByteArray)),
            this, SLOT(JWThandler(QByteArray)));

    connect(signoutTimer, SIGNAL(menuTimerRestart()),
            this, SLOT(timerResetHandler()));

    timer->start(10000);
    signoutTimer->open();
}




