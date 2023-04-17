#include "withdrawdll.h"
#include "ui_withdrawdll.h"

withdrawdll::withdrawdll(QWidget *parent, int inAccountID, bool inIsCardCredit,QString inBaseUrl,QByteArray inJwt) :
    QDialog(parent),
    ui(new Ui::withdrawdll)
{
    ui->setupUi(this);

    //sets the object to destroy itself when the window is closed
    this->setAttribute(Qt::WA_DeleteOnClose);

    Engine = new WithdrawDLLEngine(this, inAccountID, inIsCardCredit,inBaseUrl,inJwt);

    connect(ui->ReturnButton, SIGNAL(clicked()),
            this, SLOT(returnHandler()));
    connect(ui->TenEuro, SIGNAL(clicked()),
            this, SLOT(tenEuroClickHandler()));
    connect(ui->TwentyEuro, SIGNAL(clicked()),
            this, SLOT(twentyEuroClickHandler()));
    connect(ui->FiftyEuro, SIGNAL(clicked()),
            this, SLOT(fiftyEuroClickHandler()));
    connect(ui->HundredEuro, SIGNAL(clicked()),
            this, SLOT(hundredEuroClickHandler()));

    connect(this,SIGNAL(localMenuTimerResetSignal()),parent,SLOT(menuTimerRestart()));

    connect(Engine,SIGNAL(responseReady()),this,SLOT(returnHandler()));

}

withdrawdll::~withdrawdll()
{
    delete ui;
}

void withdrawdll::tenEuroClickHandler()
{
    Engine->withdraw(10);

    qDebug()<<"Withdrew 10 €";
}

void withdrawdll::twentyEuroClickHandler()
{
    Engine->withdraw(20);

    qDebug()<<"Withdrew 20 €";
}

void withdrawdll::fiftyEuroClickHandler()
{
    Engine->withdraw(50);

    qDebug()<<"Withdrew 50 €";
}

void withdrawdll::hundredEuroClickHandler()
{
    Engine->withdraw(100);

    qDebug()<<"Withdrew 100 €";
}

void withdrawdll::returnHandler()
{

    emit localMenuTimerResetSignal();

    this->close();
    qDebug()<<"Closing and destroying withdraw window";
}

