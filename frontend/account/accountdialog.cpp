#include "accountdialog.h"
#include "ui_accountdialog.h"
#include <QDebug>

accountDialog::accountDialog(QWidget *parent,int id) :
    QDialog(parent),
    ui(new Ui::accountDialog)
{
    ui->setupUi(this);

    accountID=id;

    //dialog object gets destroyed when closed
    this->setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->btnReturn,SIGNAL(clicked()),this,SLOT(backHandler()));
    connect(ui->btnReturn,SIGNAL(clicked()),parent,SLOT(menuTimerRestart()));

    connect(ui->btnPage,SIGNAL(valueChanged(int)),this, SLOT(pageChange()));
    connect(ui->btnPage,SIGNAL(valueChanged(int)),parent,SLOT(menuTimerRestart()));
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
    stringIndex = 0;

    ui->tblHistory->clearContents();

    response_data=reply->readAll();

    //this restricts the user to increase page count if the next page would be empty
    if (response_data.count("idhistory")<15 ){
        ui->btnPage->setMaximum(ui->btnPage->value());
    }

    qDebug()<<page;

    //qDebug()<<"DATA : "+response_data;
    //qDebug()<<response_data.count("idhistory");


    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);


    QJsonArray json_array = json_doc.array();
    QString history;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();

        ui->tblHistory->setItem(stringIndex,0, new QTableWidgetItem(json_obj["wholeName"].toString()));

        ui->tblHistory->setItem(stringIndex,1, new QTableWidgetItem(json_obj["date"].toString()));
        ui->tblHistory->setColumnWidth(1,140);

        ui->tblHistory->setItem(stringIndex,2, new QTableWidgetItem( QString::number(json_obj["withdrawal"].toDouble())+" €"));

        stringIndex += 1;

        //qDebug()<<"stringIndex inside foreach: "<<stringIndex;
    }
    //qDebug()<<"stringIndex outside foreach: "<<stringIndex;

    ui->teHistory->setText(history);

    reply->deleteLater();
    getManager->deleteLater();

}

void accountDialog::backHandler()
{

    this->close();
}

void accountDialog::pageChange()
{

    // changes the page which is shown by the value that is in the qSpinbox
    historyNetwork(ui->btnPage->value());
}
