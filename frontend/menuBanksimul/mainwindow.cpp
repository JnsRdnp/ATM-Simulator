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


    //main menu timer
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(eliminateMenu()));
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

    delete Timer;
    Timer = nullptr;

    delete ui;

}

void MainWindow::saldoClickHandler()
{
    //second parameter is the accountID
    pBalanceDialog = new balanceDialog(this,2);
    pBalanceDialog->show();
}

void MainWindow::nostoClickHandler()
{
    pWithdraw = new withdrawdll(this,2,true);
    pWithdraw->open();
}

void MainWindow::tiliClickHandler()
{
    emit menuTimerRestartSignal();

    pAccountDialog = new accountDialog(this,2);
    pAccountDialog->open();
}

void MainWindow::kirjauduUloshandler()
{
    //login->open();
    close();
}

void MainWindow::menuTimerRestart()
{
    qDebug()<<"menutimer restart \r";

    Timer->start(timeout);
}

void MainWindow::eliminateMenu()
{
    //this->close();
    qDebug()<<"Time is up";
}

void MainWindow::generalMenuListHandler(QListWidgetItem *item)
{
    if (ui->listMenu->item(0) == item) {
        saldoClickHandler();
    }
    if (ui->listMenu->item(1) == item){
        nostoClickHandler();
    }
    if (ui->listMenu->item(2) == item){
        tiliClickHandler();
    }
    if (ui->listMenu->item(3) == item){
        kirjauduUloshandler();
    }


}




