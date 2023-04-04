#include "nostoui.h"
#include "ui_nostoui.h"

nostoUI::nostoUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nostoUI)
{
    ui->setupUi(this);
    setWindowTitle("nosto");

    connect(ui->takaisin,SIGNAL(clicked(bool)),
                this, SLOT(takaisinClickHandler()));

}

nostoUI::~nostoUI()
{
    delete ui;
}

void nostoUI::takaisinClickHandler()
{
    close();
}
