#include "signouttimerinterface.h"
#include "ui_singouttimerinterface.h"
SignoutTimerInterface::SignoutTimerInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SingoutTimerInterface)
{
    ui->setupUi(this);
    Engine = new SignoutTimerEngine(this);
    connect(ui->AgreeButton,SIGNAL(clicked(bool)),
            this, SLOT(agreeButtonHandler()));

    connect(ui->DisagreeButton,SIGNAL(clicked(bool)),
            this, SLOT(disagreeButtonHandler()));

    connect(Engine, SIGNAL(newJsonWebToken(QByteArray)),
            this, SLOT(newJsonWebTokenHandler(QByteArray)));

}

SignoutTimerInterface::~SignoutTimerInterface()
{
    delete ui;
}

void SignoutTimerInterface::agreeButtonHandler()
{
    Engine->continueSession();
}

void SignoutTimerInterface::disagreeButtonHandler()
{
    //Engine->destroyMenu();
}

void SignoutTimerInterface::newJsonWebTokenHandler(QByteArray jwt)
{
    emit newJsonWebToken(jwt);
}
