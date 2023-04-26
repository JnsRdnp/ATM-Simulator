#include "accountchoice.h"
#include "ui_accountchoice.h"

AccountChoice::AccountChoice(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::AccountChoice)
{
    ui->setupUi(this);
    connect(ui->AccountList, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(selectHandler(QListWidgetItem*)));
    //qDebug()<<"Luodaan AC";
}

AccountChoice::~AccountChoice()
{
    delete ui;
}

void AccountChoice::setQJsonArray(QJsonArray accountArray)
{
//    qDebug()<<accountArray;
//    qDebug()<<accountArray.empty();
//    qDebug()<<"luodaan esineet";
    foreach (const QJsonValue &value, accountArray) {
        QJsonObject json_obj = value.toObject();
        //qDebug()<<json_obj["idaccounts"].toString();
        //(QChar(0x27A1)+
        QListWidgetItem* currentItem = new QListWidgetItem

            (QChar(0x27A1)+QString("  Tilinumero: ")+
                            QString::number(json_obj["idaccounts"].toInt())+
                            QString("  [ Saldo: ")+
                            QString::number(json_obj["balance"].toDouble())+
                            QString(" € ]")+
                            QString(" [ Luotto: ")+
                            QString::number(json_obj["creditLimit"].toDouble())+
                            QString(" € ]"));



        currentItem->setTextAlignment( Qt::AlignCenter );
        currentItem->setFont(QFont("Segoe UI",25));


        ui->AccountList->addItem(currentItem);
        ui->AccountList->setSpacing(50);
        //ui->AccountList->setFixedSize(ui->AccountList->sizeHintForColumn(0) + ui->AccountList->frameWidth() * 2, ui->AccountList->sizeHintForRow(0) * ui->AccountList->count() + 2 * ui->AccountList->frameWidth());

        //ui->AccountList->setFont(QFont("Segoe UI",25));
        //ui->AccountList->setAttribute()

    }
}

void AccountChoice::selectHandler(QListWidgetItem *item)
{

    QString selectedAccount = item->text();

    //This parses the account id number form the qList item
    QStringList parsedSelectedAccount = selectedAccount.split(" "); // split the string at the spaces
    for (QString part : parsedSelectedAccount) {
        if (part.contains(QRegularExpression("\\d+"))) { // check if the part contains a number
            //qDebug()<<"part is: "<<part;

            emit selectedAccountSender(part);
            break;
        }
    }
    //selectedAccount.cend()->isSymbol()
    //qDebug()<<"Selected account: "<<selectedAccount;
}
