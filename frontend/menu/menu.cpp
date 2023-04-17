#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent, QString inPIN, QString inCardID, bool inIsCardCredit, int inAccountID, QString IN_BASE_URL, QByteArray inJWT)
    : QDialog(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    PIN = inPIN;
    cardID = inCardID;
    isCardCredit = inIsCardCredit;
    accountID = inAccountID;
    BASE_URL = IN_BASE_URL;
    JWT = inJWT;


    qDebug()<<"Yhdistetään widget";
    connect(ui->listMenu, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(generalMenuListHandler(QListWidgetItem*)));

    //main menu timer;
    qDebug()<<"Luodaan ajastin";
    MainMenuTimer = new QTimer(this);
    MainMenuTimer->start(timeout);

    connect(MainMenuTimer, SIGNAL(timeout()), this, SLOT(timedSignout()));
    connect(this, SIGNAL(menuTimerRestartSignal()), this, SLOT(menuTimerRestart()));
    qDebug()<<"Ajastimet luotu";
}

Menu::~Menu()
{
//    delete pBalanceDialog;
    pBalanceDialog = nullptr;

//    delete pAccountDialog;
    pAccountDialog = nullptr;

//    delete pWithdraw;
    pWithdraw = nullptr;

//    delete timers;
    MainMenuTimer = nullptr;

    delete ui;

}

void Menu::saldoClickHandler()
{
    pBalanceDialog = new balanceDialog(this, accountID, BASE_URL, JWT);
    pBalanceDialog->show();
    emit menuTimerRestartSignal();
}

void Menu::nostoClickHandler()
{
    pWithdraw = new withdrawdll(this,accountID, isCardCredit, BASE_URL, JWT);
    pWithdraw->open();
    emit menuTimerRestartSignal();
}

void Menu::tiliClickHandler()
{
    pAccountDialog = new accountDialog(this, accountID, BASE_URL, JWT);
    pAccountDialog->open();
    emit menuTimerRestartSignal();
}

void Menu::signOutHandler()
{
    //login->open();
    this->close();
}

void Menu::menuTimerRestart()
{
    qDebug()<<"menutimer restart \r";
    MainMenuTimer->start(timeout);
}

void Menu::JWThandler(QByteArray jwt)
{
    qDebug()<<jwt;
    JWT = jwt;
    qDebug()<<"Time is up";
}


void Menu::generalMenuListHandler(QListWidgetItem *item)
{
    if (ui->listMenu->item(0) == item) {
        saldoClickHandler();
    }
    if (ui->listMenu->item(1) == item){
        nostoClickHandler();
    }
    if (ui->listMenu->item(2) == item){
        tiliClickHandler();
    }
    if (ui->listMenu->item(3) == item){
        signOutHandler();
    }
}


void Menu::timerResetHandler()
{
    MainMenuTimer->start();
}

void Menu::timedSignout()
{
    //timed signout
    qDebug()<<"Tää menee jostakin syystä täällä rikki";
    signoutTimer = SignoutTimerInterface::getInstance(this, cardID, PIN, BASE_URL);

    connect(signoutTimer, SIGNAL(newJsonWebToken(QByteArray)),
           this, SLOT(JWThandler(QByteArray)));
    connect(signoutTimer, SIGNAL(menuTimerRestart()),
           this, SLOT(timerResetHandler()));
    connect(signoutTimer, SIGNAL(destroyMenu()),
           this, SLOT(signOutHandler()));


    signoutTimer->open();
}
