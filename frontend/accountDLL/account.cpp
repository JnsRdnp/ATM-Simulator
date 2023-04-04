#include "account.h"
#include "ui_account.h"

account::account(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::account)
{
    ui->setupUi(this);
    accountOpen();
}

account::~account()
{
    delete ui;

}

void account::getBalanceSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString balance;
    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       balance+=QString::number(json_obj["balance"].toDouble())+" €";
    }

    ui->leBalance->setText(balance);

    reply->deleteLater();
    getManager->deleteLater();
}

void account::getHistorySlot(QNetworkReply *reply)
{

}

void account::accountOpen()
{
    QString site_url="http://localhost:4000/accounts/getBalance/2";
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer xRstgr...";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getBalanceSlot(QNetworkReply*)));

    reply = getManager->get(request);
}
