#include "accountchoice.h"
#include "ui_accountchoice.h"

AccountChoice::AccountChoice(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::AccountChoice)
{
    ui->setupUi(this);
    connect(ui->AccountList, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(selectHandler(QListWidgetItem*)));
    qDebug()<<"Luodaan AC";
}

AccountChoice::~AccountChoice()
{
    delete ui;
}

void AccountChoice::setQJsonArray(QJsonArray accountArray)
{
    qDebug()<<accountArray;
    qDebug()<<accountArray.empty();
    qDebug()<<"luodaan esineet";
    foreach (const QJsonValue &value, accountArray) {
        QJsonObject json_obj = value.toObject();
        qDebug()<<json_obj["idaccounts"].toString();
        ui->AccountList->addItem(new QListWidgetItem(QString::number(json_obj["idaccounts"].toInt())));
        qDebug()<<QString::number(json_obj["idaccounts"].toInt());

    }
}

void AccountChoice::selectHandler(QListWidgetItem *item)
{
    QString selectedAccount = item->text();
    qDebug()<<selectedAccount;
    emit selectedAccountSender(selectedAccount);
}
