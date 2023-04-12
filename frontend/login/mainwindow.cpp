#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int pinNumber = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    connect(pRFIDreader,SIGNAL(sendTimeoutToMainWindow()),
                this,SLOT(handleRFIDTimeout()));
    pincodep = new pincode(this);
    pincodep->open();
    updateUI();
}

void MainWindow::receivePinNumber(short num)
{
    pinNumber = num;
}


void MainWindow::updateUI()
{
    ui->textPin->setText(QString::number(pinNumber));
}

