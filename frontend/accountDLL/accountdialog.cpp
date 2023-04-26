#include "accountdialog.h"
#include "ui_accountdialog.h"
#include <QDebug>

accountDialog::accountDialog(QWidget *parent,int id,QString inBaseUrl,QByteArray inJwt) :
    QDialog(parent),
    ui(new Ui::accountDialog)
{
    ui->setupUi(this);
    accountID=id;
    baseUrl = inBaseUrl;
    jwt = inJwt;
    //qDebug()<<"JWT on"<<jwt;

    //dialog object gets destroyed when closed
    this->setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->btnReturn,SIGNAL(clicked()),this,SLOT(backHandler()));
    connect(ui->btnReturn,SIGNAL(clicked()),parent,SLOT(menuTimerRestart()));
    connect(ui->btnPage,SIGNAL(valueChanged(int)),this, SLOT(pageChange()));
    connect(ui->btnPage,SIGNAL(valueChanged(int)),parent,SLOT(menuTimerRestart()));
    //qDebug()<<jwt<<"and"<<baseUrl;

    ui->btnReturn->setText((QChar(0x2B05)+QString(" Takaisin")));

    historyNetwork(1);
}

accountDialog::~accountDialog()
{
    delete ui;
    //qDebug()<<"Account dialog deleted";
}

void accountDialog::historyNetwork(int historyPage)
{

    QString accountIDStr = QString::number(accountID);
    page=QString::number(historyPage-1);

    QString site_url=baseUrl+"history/getPage/"+accountIDStr+"/15/"+page;
    //qDebug()<<site_url;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(jwt));
    //WEBTOKEN LOPPU

    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getHistorySlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void accountDialog::scalingUI()
{
    int windowWidth = this->size().width();
    int windowHeight = this->size().width();

    int cellHeight = windowHeight/15;

    ui->tblHistory->setFixedHeight(windowHeight/3);

    ui->tblHistory->setColumnWidth(0,windowWidth/3);
    ui->tblHistory->setColumnWidth(1,windowWidth/3);
    //ui->tblHistory->setRowHeight(0,cellHeight);

    ui->tblHistory->setFont(QFont("Segoe UI",cellHeight/3));

    for(int x=0; x<16; x++){
        ui->tblHistory->setRowHeight(x, 2);
        //qDebug()<<x<<"/r";
    }


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

    //qDebug()<<page;

    //qDebug()<<"DATA : "+response_data;
    //qDebug()<<response_data.count("idhistory");


    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);


    QJsonArray json_array = json_doc.array();
    QString history;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();

        QTableWidgetItem* wholeName = new QTableWidgetItem(json_obj["wholeName"].toString());
        wholeName->setTextAlignment( Qt::AlignCenter );

        QTableWidgetItem* date = new QTableWidgetItem(json_obj["date"].toString());
        date->setTextAlignment( Qt::AlignCenter );

        QTableWidgetItem* withdrawal = new QTableWidgetItem(QString::number(json_obj["withdrawal"].toDouble())+" €");
        withdrawal->setTextAlignment( Qt::AlignCenter );

        ui->tblHistory->setItem(stringIndex,0, wholeName);

        ui->tblHistory->setItem(stringIndex,1, date);

        ui->tblHistory->setItem(stringIndex,2, withdrawal);

        scalingUI();

        stringIndex += 1;
        //qDebug()<<"stringIndex inside foreach: "<<stringIndex;
    }

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
    ui->tblHistory->scrollToTop();
}
