#include "omattiedot.h"
#include "ui_omattiedot.h"

omatTiedot::omatTiedot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::omatTiedot)
{
    ui->setupUi(this);
}

omatTiedot::~omatTiedot()
{
    delete ui;
}
