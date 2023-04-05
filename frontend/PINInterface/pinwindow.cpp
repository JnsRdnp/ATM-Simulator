#include "pinwindow.h"
#include "ui_pinwindow.h"

PINWindow::PINWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PINWindow)
{
    ui->setupUi(this);
}

PINWindow::~PINWindow()
{
    delete ui;
}

void PINWindow::on_btnPin_clicked()
{
    QString cardnum=ui->textCard->text();
    QString pincode=ui->textPin->text();
    QJsonObject jsonObj;
    jsonObj.insert("cardID", 1);
    jsonObj.insert("PINcode", 1234);
    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    postManager=new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(postCredentials(QNetworkReply*)));
    reply=postManager->post(request, QJsonDocument(jsonObj).toJson());

}

void PINWindow::httpRequestSlot(){
    response_data=reply->readAll();
    qDebug()<<response_data;
    httpResponse=response_data;
    emit httpResponseReady();
    reply->deleteLater();
    postManager->deleteLater();
}

QString PINWindow::getHttpResponse() const
{
    return httpResponse;
}

void PINWindow::setHttpResponse(const QString &newHttpResponse)
{
    httpResponse = newHttpResponse;
}

