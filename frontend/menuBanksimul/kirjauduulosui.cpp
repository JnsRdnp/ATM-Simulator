#include "kirjauduulosui.h"
#include "ui_kirjauduulosui.h"

kirjauduUlosUI::kirjauduUlosUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kirjauduUlosUI)
{
    ui->setupUi(this);
    setWindowTitle("kirjaudu ulos");

}

kirjauduUlosUI::~kirjauduUlosUI()
{
    delete ui;
}
