#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    PINInterface();
    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(postCredentials(QNetworkReply*)));
}

