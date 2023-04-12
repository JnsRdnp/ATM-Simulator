#include "signouttimerinterface.h"
#include "ui_singouttimerinterface.h"
SignoutTimerInterface::SignoutTimerInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SingoutTimerInterface)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    Engine = new SignoutTimerEngine(this);
    connect(ui->AgreeButton,SIGNAL(clicked(bool)),
            this, SLOT(agreeButtonHandler()));

    connect(ui->DisagreeButton,SIGNAL(clicked(bool)),
            this, SLOT(disagreeButtonHandler()));

    connect(Engine, SIGNAL(newJsonWebToken(QByteArray)),
            this, SLOT(newJsonWebTokenHandler(QByteArray)),Qt::QueuedConnection	);

    connect(Engine, SIGNAL(menuTimerRestart()),
            this, SLOT(restartMenuTimerHandler()),Qt::QueuedConnection);

    connect(Engine, SIGNAL(closeSignout()),
            this, SLOT(closeSignoutHandler()),Qt::QueuedConnection);

    connect(Engine, SIGNAL(eliminateMenu()),
            this, SLOT(destroymenuHandler()),Qt::QueuedConnection);
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
    Engine->destroyMenuCaller();
}

void SignoutTimerInterface::newJsonWebTokenHandler(QByteArray jwt)
{
    emit newJsonWebToken(jwt);
}

void SignoutTimerInterface::restartMenuTimerHandler()
{
    emit menuTimerRestart();
}

void SignoutTimerInterface::destroymenuHandler()
{
    this->close();
    qDebug()<<"tuhottu";
    //emit close signal
}

void SignoutTimerInterface::closeSignoutHandler()
{
    this->close();
    qDebug()<<"suljettu";
}
