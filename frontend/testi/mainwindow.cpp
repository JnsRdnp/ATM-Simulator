#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    signoutTimer = new SignoutTimerInterface(this);
    timer = new QTimer(this);

    connect(signoutTimer, SIGNAL(newJsonWebToken(QByteArray)),
            this, SLOT(JWThandler(QByteArray)));

    connect(signoutTimer, SIGNAL(menuTimerRestart()),
            this, SLOT(timerResetHandler()));

    timer->start(10000);
    signoutTimer->open();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::JWThandler(QByteArray jwt)
{
    qDebug()<<jwt;
}

void MainWindow::timerResetHandler()
{
    qDebug() << "timer before " << timer->remainingTime();
    timer->start();         //timer restarts
    qDebug() << "timer after " << timer->remainingTime();
}

