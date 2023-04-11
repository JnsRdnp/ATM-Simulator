#include "singouttimerinterface.h"
#include "ui_singouttimerinterface.h"

SingoutTimerInterface::SingoutTimerInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SingoutTimerInterface)
{
    ui->setupUi(this);
    connect(ui->AgreeButton,SIGNAL(clicked(bool)),
            this, SLOT(agreeButtonHandler()));

    connect(ui->DisagreeButton,SIGNAL(clicked(bool)),
            this, SLOT(disagreeButtonHandler()));

    Engine = new SignoutTimerEngine(this);

}

SingoutTimerInterface::~SingoutTimerInterface()
{
    delete ui;
}

void SingoutTimerInterface::agreeButtonHandler()
{

}

void SingoutTimerInterface::disagreeButtonHandler()
{
    //Engine->destroyMenu();
}
