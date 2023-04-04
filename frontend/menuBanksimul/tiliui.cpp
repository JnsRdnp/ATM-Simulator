#include "tiliui.h"
#include "ui_tiliui.h"

tiliUI::tiliUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tiliUI)
{
    ui->setupUi(this);
    setWindowTitle("tili");

    connect(ui->takaisin,SIGNAL(clicked(bool)),
                this, SLOT(takaisinClickHandler()));
}

tiliUI::~tiliUI()
{
    delete ui;
}

void tiliUI::takaisinClickHandler()
{
    close();
}
