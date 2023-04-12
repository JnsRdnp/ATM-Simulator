#include "pincode.h"
#include "ui_pincode.h"

pincode::pincode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pincode)
{
    ui->setupUi(this);
    connect(ui->btnPin, SIGNAL(clicked(bool)),
            this, SLOT(on_btnPin_clicked()));
}

pincode::~pincode()
{
    delete ui;
}

void pincode::on_btnPin_clicked()
{
    QString pincode = ui->textPin->text();
    emit sendPin(pincode.toShort());
    done(0);
}

