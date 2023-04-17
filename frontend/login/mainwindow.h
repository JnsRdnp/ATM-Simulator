#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "pincode.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void receivePinNumber(short);
    void on_pushButton_2_clicked();
    void on_btnCredentials_clicked();
    void addLoginSlot(QNetworkReply * reply);

private:
    Ui::MainWindow *ui;
    pincode * pincodep;
    void updateUI();
    void checkCredentials();
    short pinCode, attempts;
    void checkNumber();
    QNetworkAccessManager *postManager;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray token;
};
#endif // MAINWINDOW_H
