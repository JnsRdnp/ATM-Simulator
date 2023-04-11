#include "singouttimerinterface.h"
#include "ui_singouttimerinterface.h"

SingoutTimerInterface::SingoutTimerInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SingoutTimerInterface)
{
    ui->setupUi(this);
}

SingoutTimerInterface::~SingoutTimerInterface()
{
    delete ui;
}
