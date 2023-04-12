#include "balancedialog.h"
#include "ui_balancedialog.h"

balanceDialog::balanceDialog(QWidget *parent, int id) :
    QDialog(parent),
    ui(new Ui::balanceDialog)
{
    ui->setupUi(this);
    accountID=id;

    //dialog object gets destroyed when closed
    this->setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->btnReturn,SIGNAL(clicked()),this,SLOT(backHandler()));
    balanceNetwork();
    //historyNetwork();
}

balanceDialog::~balanceDialog()
{
    qDebug()<<"Balance object destroyed";
    delete ui;
}

void balanceDialog::balanceNetwork()
{
    QString accountIDStr = QString::number(accountID);
    QString site_url="http://localhost:3000/accounts/getBalance/"+accountIDStr;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer xRstgr...";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getBalanceSlot (QNetworkReply*)));

    balanceReply = getManager->get(request);
}

void balanceDialog::getBalanceSlot(QNetworkReply *balanceReply)
{
    response_data=balanceReply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString balance;
    QString creditLimit;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        balance+=QString::number(json_obj["balance"].toDouble())+" €";
        creditLimit+=QString::number(json_obj["creditLimit"].toDouble())+" €";
    }

    ui->lblBalance->setText(balance);
    ui->lblCreditlimit->setText(creditLimit);

    balanceReply->deleteLater();
    getManager->deleteLater();

    // start historyNetwork() to get the latest history also
    historyNetwork();
}

void balanceDialog::historyNetwork()
{

    QString accountIDStr = QString::number(accountID);

    QString site_url="http://localhost:3000/history/getPage/"+accountIDStr+"/5/0";
    //qDebug()<<site_url;
    QNetworkRequest request((site_url));

    //WEBTOKEN ALKU
    QByteArray myToken="Bearer xRstgr...";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getHistorySlot(QNetworkReply*)));

    historyReply = getManager->get(request);
}

void balanceDialog::getHistorySlot(QNetworkReply *historyReply)
{

    response_data=historyReply->readAll();

    //qDebug()<<"DATA : "+response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString history;

    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        history+=json_obj["wholeName"].toString()+"    |    "+json_obj["date"].toString()+"    |    "+
                   QString::number(json_obj["withdrawal"].toDouble())+" €"+"\r\r";
    }


    ui->txtLatestHistory->setText(history);

    historyReply->deleteLater();
    getManager->deleteLater();
}

void balanceDialog::backHandler()
{
    this->close();
}
