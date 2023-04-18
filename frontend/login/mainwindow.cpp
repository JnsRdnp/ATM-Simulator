#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "environment.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    pinCode = "";
    attempts = 3;
    ui->setupUi(this);
    ui->pushButton->setEnabled(true);
    updateUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    updateUI();
    qDebug()<<"clicked button";
    pPincode = new pincode(this);
    connect(pPincode, SIGNAL(sendPin(QString)),
            this,SLOT(receivePinNumber(QString)));
    pPincode->open();
    updateUI();

}

void MainWindow::receivePinNumber(QString num)
{
    qDebug()<<"received pin";
    pinCode = num;
    pPincode->deleteLater();
    //pincodep = nullptr;
    updateUI();
}

void MainWindow::updateUI() {
    ui->textPin->setText(pinCode);
    ui->textAttempts->setText("Attempts = " + QString::number(attempts));
}

void MainWindow::checkNumber()
{
    updateUI();
}


void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_btnCredentials_clicked()
{
    qDebug()<<"Pressed a button";
    QString cardID = ui->textCard->text();
    QString PINcode = ui->textPin->text();
    QJsonObject jsonObj;
    jsonObj.insert("cardID", cardID);
    jsonObj.insert("PINcode", PINcode);
    QString site_url= Environment::getBaseUrl() + "/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(addLoginSlot(QNetworkReply*)));
    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());
    qDebug()<<reply;
}

void MainWindow::addLoginSlot(QNetworkReply *reply) {
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    postManager->deleteLater();
    checkCredentials();
}

void MainWindow::checkCredentials()
{
    if(QString::compare(response_data, "false")!=0){
        token="Bearer "+response_data;
        choice = new Choices(this);
        choice->open();
    }
    else if (QString::compare(response_data, "false")==0){
        attempts--;
    }
    if (attempts == 0) {
        ui->pushButton->setEnabled(false);
        ui->btnCredentials->setEnabled(false);
    }
    updateUI();
}
