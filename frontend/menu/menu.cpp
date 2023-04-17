#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->listMenu, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(generalMenuListHandler(QListWidgetItem*)));


    //main menu timer;
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(timedSignout()));
    Timer->start(timeout);

    connect(this,SIGNAL(menuTimerRestartSignal()),this,SLOT(menuTimerRestart()));

}

Menu::~Menu()
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

void Menu::saldoClickHandler()
{
    //second parameter is the accountID
    pBalanceDialog = new balanceDialog(this,2);
    pBalanceDialog->show();
    emit menuTimerRestartSignal();
}

void Menu::nostoClickHandler()
{
    pWithdraw = new withdrawdll(this,2,true);
    pWithdraw->open();
    emit menuTimerRestartSignal();
}

void Menu::tiliClickHandler()
{
    pAccountDialog = new accountDialog(this,2);
    pAccountDialog->open();
    emit menuTimerRestartSignal();
}

void Menu::kirjauduUloshandler()
{
    //login->open();
    this->close();
}

void Menu::menuTimerRestart()
{
    qDebug()<<"menutimer restart \r";
    Timer->start(timeout);
}

void Menu::JWThandler(QByteArray jwt)
{
    qDebug()<<jwt;
    //this->close();
    qDebug()<<"Time is up";
}


void Menu::generalMenuListHandler(QListWidgetItem *item)
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


void Menu::timerResetHandler()
{
    qDebug() << "timer before " << timer->remainingTime();
    timer->start();         //timer restarts
    qDebug() << "timer after " << timer->remainingTime();
}

void Menu::timedSignout()
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
