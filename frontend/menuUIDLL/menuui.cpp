#include "menuui.h"
#include "ui_menuui.h"

menuUI::menuUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menuUI)
{
    ui->setupUi(this);
    setWindowTitle("main menu");

        connect(ui->saldo,SIGNAL(clicked(bool)),
                    this, SLOT(saldoClickHandler()));

        //pSaldoUI = new saldoUI(this);

        connect(ui->nosto,SIGNAL(clicked(bool)),
                    this, SLOT(nostoClickHandler()));

        //pnostoUI = new nostoUI(this);

        connect(ui->tili,SIGNAL(clicked(bool)),
                    this, SLOT(tiliClickHandler()));

        //ptiliUI = new tiliUI(this);

        connect(ui->ulos,SIGNAL(clicked(bool)),
                    this, SLOT(kirjauduUloshandler()));


}

menuUI::~menuUI()
{
    delete ui;
}

void menuUI::saldoClickHandler()
{
    //saldoUI->open();
}

void menuUI::nostoClickHandler()
{
    //nostoUI->open();
}

void menuUI::tiliClickHandler()
{
    //tiliUI->open();
}

void menuUI::kirjauduUloshandler()
{
    close();
    //login->open();
}

void menuUI::timeoutHandler()
{
    aika++;
    if (aika >= 5000){
        close();
    }
}

void menuUI::loginSlot(QNetworkReply *reply)
{
}
