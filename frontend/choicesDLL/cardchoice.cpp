#include "cardchoice.h"
#include "ui_cardchoice.h"

CardChoice::CardChoice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CardChoice)
{
    ui->setupUi(this);
    connect(ui->CreditButton, SIGNAL(clicked()),
            this, SLOT(choiceHandler()));
    connect(ui->DebitButton, SIGNAL(clicked()),
            this, SLOT(choiceHandler()));
}

CardChoice::~CardChoice()
{
    delete ui;
}

void CardChoice::choiceHandler()
{
    //qDebug()<<"hello";
    //gets the buttons name and sets it to QString name
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();

    //qDebug()<<name;
    emit cardChoice(name);
}
