#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "saldoui.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->saldo,SIGNAL(clicked(bool)),
                this, SLOT(saldoClickHandler()));

    pSaldoUI = new saldoUI(this);

    connect(ui->nosto,SIGNAL(clicked(bool)),
                this, SLOT(nostoClickHandler()));

    pnostoUI = new nostoUI(this);

    connect(ui->tili,SIGNAL(clicked(bool)),
                this, SLOT(tiliClickHandler()));

    ptiliUI = new tiliUI(this);

    connect(ui->kirjauduUlos,SIGNAL(clicked(bool)),
                this, SLOT(kirjauduUloshandler()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saldoClickHandler()
{
    pSaldoUI->open();
}

void MainWindow::nostoClickHandler()
{
    pnostoUI->open();
}

void MainWindow::tiliClickHandler()
{
    ptiliUI->open();
}

void MainWindow::kirjauduUloshandler()
{
    //login->open();
    close();
}




