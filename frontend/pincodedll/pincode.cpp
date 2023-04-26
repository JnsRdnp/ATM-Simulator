#include "pincode.h"
#include "ui_pincode.h"

bool secondNumberTyping = false;
short pinPressed = 4;

pincode::pincode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pincode)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->btnPin, SIGNAL(clicked(bool)),
            this, SLOT(on_btnPin_clicked()));
    connect(ui->pushButton_0, SIGNAL(released()),
            this, SLOT(digit_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()),
            this, SLOT(digit_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()),
            this, SLOT(digit_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()),
            this, SLOT(digit_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()),
            this, SLOT(digit_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()),
            this, SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()),
            this, SLOT(digit_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()),
            this, SLOT(digit_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()),
            this, SLOT(digit_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()),
            this, SLOT(digit_pressed()));
    connect(ui->btnClear, SIGNAL(released()),
            this, SLOT(clear_pin()));
}

pincode::~pincode()
{
    //qDebug()<<"PINCODE DLL DESTROYED!!!";
    delete ui;
}

void pincode::on_btnPin_clicked()
{
    QString pincode = ui->textPin->text();
    emit sendPin(pincode);
    labelNumber = "";
    pinPressed = 4;
    this->close();
}

void pincode::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    QString newLabel;
    if (pinPressed > 0) {
        newLabel=button->text();
        labelNumber += newLabel;
        ui->textPin->setText(labelNumber);
        pinPressed--;
    }
}

void pincode::clear_pin()
{
    ui->textPin->setText("");
    labelNumber = "";
    pinPressed = 4;
}

