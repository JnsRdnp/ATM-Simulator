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

    reply = getManager->get(request);
}

void balanceDialog::getBalanceSlot(QNetworkReply *reply)
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

    ui->lblBalance->setText(balance);

    reply->deleteLater();
    getManager->deleteLater();
}

void balanceDialog::backHandler()
{
    this->close();
}
