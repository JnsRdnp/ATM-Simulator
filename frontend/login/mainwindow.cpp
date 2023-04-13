#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    pinCode = 0;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    updateUI();
    pincodep = new pincode(this);
    connect(pincodep, SIGNAL(sendPin(short)),
            this,SLOT(receivePinNumber(short)));
    pincodep->open();
    updateUI();

}

void MainWindow::receivePinNumber(short num)
{
    pinCode = num;
    delete pincodep;
    pincodep = nullptr;
}

void MainWindow::updateUI() {
    ui->textPin->setText(QString::number(pinCode));
}

void MainWindow::checkNumber()
{
    updateUI();
}

