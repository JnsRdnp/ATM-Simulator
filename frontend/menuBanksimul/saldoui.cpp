#include "saldoui.h"
#include "ui_saldoui.h"

saldoUI::saldoUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saldoUI)
{
    ui->setupUi(this);
    setWindowTitle("saldo");

    connect(ui->takaisin,SIGNAL(clicked(bool)),
                this, SLOT(takaisinClickHandler()));
}

saldoUI::~saldoUI()
{
    delete ui;
}

void saldoUI::takaisinClickHandler()
{
    close();
}
