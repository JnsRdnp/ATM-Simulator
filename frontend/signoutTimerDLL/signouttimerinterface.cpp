#include "signouttimerinterface.h"
#include "ui_signouttimerinterface.h"

SignoutTimerInterface* SignoutTimerInterface::instance = nullptr;

SignoutTimerInterface* SignoutTimerInterface::getInstance(QWidget *parent, QString inCardID, QString inPIN, QString IN_BASE_URL)
{
    if (instance == nullptr)
    {
        instance = new SignoutTimerInterface(parent, inCardID, inPIN, IN_BASE_URL);
    }

    return instance;
}

SignoutTimerInterface::SignoutTimerInterface(QWidget *parent, QString inCardID, QString inPIN, QString IN_BASE_URL) :
    QDialog(parent),
    ui(new Ui::SingoutTimerInterface)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    Engine = new SignoutTimerEngine(this, inCardID, inPIN, IN_BASE_URL);
    connect(ui->pushButton,SIGNAL(clicked(bool)),
            this, SLOT(agreeButtonHandler()));

    connect(ui->pushButton_2,SIGNAL(clicked(bool)),
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
    instance = nullptr;
}

void SignoutTimerInterface::agreeButtonHandler()
{
    Engine->continueSession();
}

void SignoutTimerInterface::disagreeButtonHandler()
{
    Engine->destroyMenu();
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
    //emit close signal;
}

void SignoutTimerInterface::closeSignoutHandler()
{
    this->close();
    qDebug()<<"suljettu";
}
