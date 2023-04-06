#include "withdrawdll.h"
#include "ui_withdrawdll.h"

withdrawdll::withdrawdll(QWidget *parent, int inAccountID, bool inIsCardCredit, QByteArray inJwt) :
    QDialog(parent),
    ui(new Ui::withdrawdll)
{
    ui->setupUi(this);

    Engine = new WithdrawDLLEngine(this, inAccountID, inIsCardCredit, inJwt);

    connect(ui->TenEuro, SIGNAL(clicked()),
            this, SLOT(tenEuroClickHandler()));
    connect(ui->TwentyEuro, SIGNAL(clicked()),
            this, SLOT(twentyEuroClickHandler()));
    connect(ui->FiftyEuro, SIGNAL(clicked()),
            this, SLOT(fiftyEuroClickHandler()));
    connect(ui->HundredEuro, SIGNAL(clicked()),
            this, SLOT(hundredEuroClickHandler()));
}

withdrawdll::~withdrawdll()
{
    delete ui;
}

void withdrawdll::tenEuroClickHandler()
{
    Engine->withdraw(10);
    qDebug()<<"Withdrew 50 €";
}

void withdrawdll::twentyEuroClickHandler()
{
    Engine->withdraw(20);
    qDebug()<<"Withdrew 50 €";
}

void withdrawdll::fiftyEuroClickHandler()
{
    Engine->withdraw(50);
    qDebug()<<"Withdrew 50 €";
}

void withdrawdll::hundredEuroClickHandler()
{
    Engine->withdraw(100);
    qDebug()<<"Withdrew 50 €";
}

