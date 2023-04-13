#include "errorscreen.h"
#include "ui_errorscreen.h"

ErrorScreen::ErrorScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorScreen)
{
    ui->setupUi(this);
    connect(ui->ok, SIGNAL(clicked()),
            this, okClickHandler());
}

ErrorScreen::~ErrorScreen()
{
    delete ui;
}

void ErrorScreen::okClickHandler()
{
    emit okClickedSignal();
}
