#include "errorscreen.h"
#include "ui_errorscreen.h"

ErrorScreen::ErrorScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorScreen)
{
    ui->setupUi(this);

    //error screen gets destroyed when closed
    this->setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->ok, SIGNAL(clicked()),
            this, SLOT(okClickHandler()));
}

ErrorScreen::~ErrorScreen()
{
    delete ui;
}

void ErrorScreen::okClickHandler()
{
    emit okClickedSignal();
}
