#include "cardreader.h"
#include "ui_cardreader.h"

#include <QSerialPort>
#include <QDebug>

CardReader::CardReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CardReader)
{
    qDebug() << "Creating CardReader";
    ui->setupUi(this);
    qDebug() << "Connecting Read Button";
//    connect(ui->Read,SIGNAL(clicked()),
//            this, SLOT(ReadSignal_clicked()));
    qDebug() << "Opening Serial Port";
    openSerialPort();
}

CardReader::~CardReader()
{
    qDebug()<<"cardreader DESTRUCTOR";
    delete ui;
    serial->clear();
    if (serial->isOpen()){
        serial->close();
    };
    delete serial;
    serial = nullptr;
}

void CardReader::ReadSignal_clicked()
{
    readSerialPort();
    qDebug()<<"Trying to send";
    if (cardID.length() > 0 && !cardID.isEmpty()){
        qDebug()<<"Sent";
        emit RFIDSignal(cardID);
       }
}

void CardReader::openSerialPort()
{
    serial =  new QSerialPort;
    //Setup the Serial connection
    serial->setPortName("COM3");
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


