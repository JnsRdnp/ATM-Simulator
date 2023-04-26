#ifndef MENU_H
#define MENU_H

#include "menu_global.h"
#include "qlistwidget.h"
#include "signouttimerinterface.h"
#include "balancedialog.h"
#include "accountdialog.h"
#include "withdrawdll.h"
#include <QDialog>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class MENU_EXPORT Menu : public QDialog
{
    Q_OBJECT
public:
    Menu(QWidget * parent = nullptr, QString inPIN = "", QString inCardID = "", bool inIsCardCredit = false, int inAccountID = 0, QString IN_BASE_URL = "", QByteArray inJWT = "");
    ~Menu();

public slots:
    void balanceClickHandler();
    void withdrawClickHandler();
    void accountClickHandler();
    void signOutHandler();
    void menuTimerRestart();

    void generalMenuListHandler(QListWidgetItem*);
    void JWThandler(QByteArray);
    void timerResetHandler();
    void timedSignout();

signals:
    void menuTimerRestartSignal();
    void destroySignal();

private:
    Ui::Menu *ui;

    balanceDialog *pBalanceDialog;
    accountDialog *pAccountDialog;
    withdrawdll *pWithdraw;
    SignoutTimerInterface *signoutTimer;
    QTimer *MainMenuTimer;
    int timeout = 15000;

    //card info
    QString PIN = "";
    QString cardID = "";
    bool isCardCredit;
    int accountID;
    QByteArray JWT = "";
    QString BASE_URL = "";
};

#endif // MENU_H
