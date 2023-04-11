#include "accountdialog.h"
#include "ui_accountdialog.h"

accountDialog::accountDialog(QWidget *parent,int id) :
    QDialog(parent),
    ui(new Ui::accountDialog)
{
    ui->setupUi(this);

    accountID=id;

    //dialog object gets destroyed when closed
    this->setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->btnReturn,SIGNAL(clicked()),this,SLOT(backHandler()));
    connect(ui->btnPage,SIGNAL(valueChanged(int)),this, SLOT(pageChange()));
    connect(this,SIGNAL(localRestartTimerSignal()),parent,SLOT(menuTimerRestart()));
    historyNetwork(1);
}

accountDialog::~accountDialog()
{
    delete ui;
    qDebug()<<"Account dialog deleted";
}

void accountDialog::historyNetwork(int historyPage)
{

    QString accountIDStr = QString::number(accountID);
    page=QString::number(historyPage-1);

    QString site_url="http://localhost:3000/history/getPage/"+accountIDStr+"/15/"+page;
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
        history+=json_obj["wholeName"].toString()+" | "+json_obj["date"].toString()+" | "+
                   QString::number(json_obj["withdrawal"].toDouble())+" €"+"\r\r";
    }

    ui->teHistory->setText(history);

    reply->deleteLater();
    getManager->deleteLater();
}

void accountDialog::backHandler()
{
    emit localRestartTimerSignal();
    this->close();
}

void accountDialog::pageChange()
{
    emit localRestartTimerSignal();
    historyNetwork(ui->btnPage->value());
}
