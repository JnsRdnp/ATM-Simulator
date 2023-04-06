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
    qDebug()<<"Account dialog deleted";
}

void accountDialog::historyNetwork()
{

    QString site_url="http://localhost:4000/history/getPage/2/5/1";
    //qDebug()<<site_url;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer xRstgr...";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU

    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getHistorySlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void accountDialog::getHistorySlot(QNetworkReply *reply)
{

    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString history;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        history+=json_obj["wholeName"].toString()+"|"+json_obj["date"].toString()+"| "+
                   QString::number(json_obj["withdrawal"].toDouble())+" €"+"\r";
    }

    ui->teHistory->setText(history);

    reply->deleteLater();
    getManager->deleteLater();
}

void accountDialog::backHandler()
{
    this->close();
}
