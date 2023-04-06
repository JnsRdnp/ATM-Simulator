#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objPINInterface=new PINInterface;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete objPINInterface;
    objPINInterface=nullptr;
}

void MainWindow::on_btnPinLogin_clicked()
{
    connect(objPINInterface, SIGNAL(loginReady()),
            this, SLOT(loginReadySlot()));
    objPINInterface->openLogin();
}

void MainWindow::loginReadySlot()
{
    QString response = objPINInterface->getLoginResponse();
    qDebug()<<response;
}

