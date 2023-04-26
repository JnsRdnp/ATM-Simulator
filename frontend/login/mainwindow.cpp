#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "environment.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    PINCode = "";
    cardID = "";
    attempts = 3;
    ui->setupUi(this);

    ui->btnPin->setEnabled(true);

    this->setWindowState(Qt::WindowFullScreen);



    cardReader = new CardReader(this);

    connect(cardReader, SIGNAL(RFIDSignal(QString)),
            this,SLOT(receiveCardID(QString)));

    connect(ui->cardButtonNotCursed,SIGNAL(clicked()),this,SLOT(on_CardButton_clicked()));

    connect(ui->btnLogin,SIGNAL(clicked()),this, SLOT(on_btnCredentials_clicked()));

    connect(ui->btnPin,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));



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
    PINCode = num;

    updateUI();
}

void MainWindow::updateUI() {
    qDebug()<<"Update UI";
    ui->textPin->setText(PINCode);
    ui->textCard->setText(cardID);
    ui->textAttempts->setText("Yrityksiä jäljellä: " + QString::number(attempts));
    qDebug()<<attempts;
}


void MainWindow::clearLoginData()
{
    cardID = "";
    PINCode = "";
    attempts = 3;

    ui->btnPin->setEnabled(true);
    ui->btnLogin->setEnabled(true);

    updateUI();

}


void MainWindow::on_CardButton_clicked()
{
//    updateUI();
//    qDebug()<<"clicked button";
//    cardReader = new CardReader(this);
//    connect(cardReader, SIGNAL(RFIDSignal(QString)),
//            this,SLOT(receiveCardID(QString)));
//    cardReader->open();
//    updateUI();
    if (attempts<=0){
        clearLoginData();
    }

    updateUI();


    qDebug()<<"CardID is: "+cardID;

    cardReader->ReadSignal_clicked();

    updateUI();


}

void MainWindow::receiveCardID(QString inCardID)
{
    cardID = inCardID;

        //this caused problems with reading cardID multiple times
//    cardReader->deleteLater();

        //this can be used to automatically open the pindll after reading card
//    if (cardID!=""){
//            on_pushButton_clicked();
//        }

    updateUI();

}

void MainWindow::on_btnCredentials_clicked()
{

    qDebug()<<"Pressed a button";
    QJsonObject jsonObj;
    jsonObj.insert("cardID", cardID);
    jsonObj.insert("PINcode", PINCode);
    QString site_url= Environment::getBaseUrl() + "login";
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
        choice = new Choices(this, PINCode, cardID, Environment::getBaseUrl(), token);
            //commented out because this somehow created mystery "login" miniwindow
        //choice->open();
        connect(choice, SIGNAL(destroySignal()),
                this, SLOT(destroySignalHandler()));
        //clearsData from login screen if user gets in
        clearLoginData();
    }
    else if (QString::compare(response_data, "false")==0){
        attempts--;
    }
    if (attempts == 0) {
        ui->btnPin->setEnabled(false);
        ui->btnLogin->setEnabled(false);
    }
    updateUI();
}

void MainWindow::destroySignalHandler()
{
    qDebug()<<"tuhotaan choice";
    choice = nullptr;
    attempts = 3;
    PINCode = "";
    cardID = "";
    updateUI();
}
