#ifndef PINWINDOW_H
#define PINWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class PINWindow;
}

class PINWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PINWindow(QWidget *parent = nullptr);
    ~PINWindow();

    QString getHttpResponse() const;
    void setHttpResponse(const QString &newHttpResponse);

private slots:
    void on_btnPin_clicked();
    void httpRequestSlot();

private:
    Ui::PINWindow *ui;
    QString httpResponse;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;
signals:
    void httpResponseReady();
};

#endif // PINWINDOW_H
