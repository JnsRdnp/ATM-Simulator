#include "cardreader.h"
#include "ui_cardreader"

#include <QSerialPort>
#include <QDebug>

CardReader::CardReader(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CardReader)
{
    qDebug() << "Creating CardReader";
    ui->setupUi(this);
    qDebug() << "Connecting Read Button";
    connect(ui->Read,SIGNAL(clicked()),
            this, SLOT(ReadSignal_clicked()));
    qDebug() << "Opening Serial Port";
    openSerialPort();
}

CardReader::~CardReader()
{
    delete ui;
    if (serial->isOpen()){
        serial->close();
    };
    free(serial);
    serial = nullptr;
}


void CardReader::ReadSignal_clicked()
{
    readSerialPort();
    if (cardID.length() > 0 && cardID != NULL){
        qDebug() << "Create PINinterface";
        this->hide();
       }
}

void CardReader::openSerialPort()
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

void CardReader::readSerialPort()
{
    QByteArray data = serial->readAll();
    qDebug()<<data;
    cardID = QString(data);
    cardID.remove(0, 3).remove(10, cardID.length()-10);
    qDebug()<<cardID;

}

