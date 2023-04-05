#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPort>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qDebug() << "Creating MainWindow";
    ui->setupUi(this);
    qDebug() << "Connecting Read Button";
    connect(ui->Read,SIGNAL(clicked()),
            this, SLOT(ReadSignal_clicked()));
    qDebug() << "Connecting Stop Button";
    connect(ui->Stop, SIGNAL(clicked()),
            this, SLOT(StopSignal_clicked()));
    qDebug() << "Opening Serial Port";
    openSerialPort();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ReadSignal_clicked()
{
    readSerialPort();
    //cardID="1234";
    //if cardID != 0 || cardID != NULL{
    //PINInterface *PINUserInterface = new PINInterface(this, cardID);
}

void MainWindow::StopSignal_clicked()
{
    closeSerialPort();
}

void MainWindow::openSerialPort()
{
    serial =  new QSerialPort;
    //Setup the Serial connection
    serial->setPortName("COM10");
    serial->setBaudRate(9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if (!(serial->open(QIODevice::ReadWrite))) {
        qDebug() << "Error";
        };
}

void MainWindow::closeSerialPort()
{
    if (serial->isOpen()){
        serial->close();
    };
    free(serial);
    serial = nullptr;
}

void MainWindow::readSerialPort()
{
    QByteArray data = serial->readAll();
    qDebug()<<data;
    cardID = QString(data);
    cardID.remove(0, 3).chop(3);
    qDebug()<<cardID;

}

