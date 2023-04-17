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
    qDebug() << "Opening Serial Port";
    openSerialPort();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (serial->isOpen()){
        serial->close();
    };
    free(serial);
    serial = nullptr;
}


void MainWindow::ReadSignal_clicked()
{
    readSerialPort();
    if (cardID.length() > 0 && cardID != NULL){
        qDebug() << "Create PINinterface";
        this->hide();
       }
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

void MainWindow::readSerialPort()
{
    QByteArray data = serial->readAll();
    qDebug()<<data;
    cardID = QString(data);
    cardID.remove(0, 3).remove(10, cardID.length()-10);
    qDebug()<<cardID;

}

