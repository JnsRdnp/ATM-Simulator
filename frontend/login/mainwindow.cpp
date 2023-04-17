#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "environment.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    pinCode = 0;
    attempts = 3;
    ui->setupUi(this);
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
    pincodep = new pincode(this);
    connect(pincodep, SIGNAL(sendPin(short)),
            this,SLOT(receivePinNumber(short)));
    pincodep->open();
    updateUI();

}

void MainWindow::receivePinNumber(short num)
{
    qDebug()<<"received pin";
    pinCode = num;
    pincodep->deleteLater();
    //pincodep = nullptr;
    updateUI();
}

void MainWindow::updateUI() {
    ui->textPin->setText(QString::number(pinCode));
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

    //WEBTOKEN ALKU
    QByteArray myToken="Bearer xRstgr...";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(addLoginSlot(QNetworkReply*)));
    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());
    qDebug()<<reply;
    checkCredentials();
}

void MainWindow::addLoginSlot(QNetworkReply *reply) {
    response_data=reply->readAll();
    qDebug()<<response_data;
    ui->loginConfirm->setText(response_data);
    /*)
    if(QString::compare(response_data, "false")!=0){
        ui->loginConfirm->setText(response_data);
        token="Bearer "+response_data;
    } else {
        ui->textCard->clear();
        ui->textPin->clear();
    }
    */

    reply->deleteLater();
    postManager->deleteLater();
}

void MainWindow::checkCredentials()
{
    attempts--;
    updateUI();
    if(QString::compare(response_data, "false")!=0){
        ui->loginConfirm->setText(response_data);
        token="Bearer "+response_data;
        updateUI();
    }
    else {
        if (attempts == 0) {
            ui->loginConfirm->setText("3 wrong attempts, card locked");
            attempts = 3;
            updateUI();
            // qApp->exit();
        }
        else {

        }
    }
}
