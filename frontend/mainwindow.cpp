#include "mainwindow.h"
#include "PINInterface.h"
#include "ui_mainwindow.h"

#include <QSerialPort>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_CardSignal_clicked()
{
    cardID="1234";
    //if cardID != 0 || cardID != NULL{
    PINInterface *PINUserInterface = new PINInterface(this, cardID);
}

