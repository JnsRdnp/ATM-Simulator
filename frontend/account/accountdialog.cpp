#include "accountdialog.h"
#include "ui_accountdialog.h"

accountDialog::accountDialog(QWidget *parent,int id) :
    QDialog(parent),
    ui(new Ui::accountDialog)
{
    ui->setupUi(this);

    accountID=id;

    this->setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->btnBack,SIGNAL(clicked()),this,SLOT(backHandler()));
    historyNetwork();
}

accountDialog::~accountDialog()
{
    delete ui;
}

void accountDialog::historyNetwork()
{

    QString accountIDStr = QString::number(accountID);

    QJsonObject jsonObj;
    jsonObj.insert("accountID","2");
    jsonObj.insert("amount","5");
    jsonObj.insert("page","1");

    QString site_url="http://localhost:4000/history/getPage";
    QNetworkRequest request((site_url));

    //WEBTOKEN ALKU
    QByteArray myToken="Bearer xRstgr...";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getHistorySlot (QNetworkReply*)));

    reply = getManager->get(request);
}

void accountDialog::getHistorySlot(QNetworkReply *reply)
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

    ui->leHistory->setText(balance);

    reply->deleteLater();
    getManager->deleteLater();
}

void accountDialog::backHandler()
{
    this->close();
}
