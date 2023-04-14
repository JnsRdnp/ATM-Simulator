#include "accountchoice.h"
#include "ui_accountchoice.h"

AccountChoice::AccountChoice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountChoice)
{
    ui->setupUi(this);
}

AccountChoice::~AccountChoice()
{
    delete ui;
}
