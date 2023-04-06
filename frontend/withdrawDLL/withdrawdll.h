#ifndef WITHDRAWDLL_H
#define WITHDRAWDLL_H

#include "WithdrawDLL_global.h"
#include "withdrawdllengine.h"

#include <QDialog>
#include <QDebug>

namespace Ui {
class withdrawdll;
}

class WITHDRAWDLL_EXPORT withdrawdll : public QDialog
{
    Q_OBJECT

public:
    explicit withdrawdll(QWidget *parent = nullptr, int inAccountID = 0, bool inIsCardCredit = false, QString inJwt = "");
    ~withdrawdll();

private slots:
    void tenEuroClickHandler();
    void twentyEuroClickHandler();
    void fiftyEuroClickHandler();
    void hundredEuroClickHandler();

private:
    int accountID;
    bool isCardCredit;
    QString jwt;
    //WithdrawDLLEngine * Engine;
    Ui::withdrawdll *ui;
};

#endif // WITHDRAWDLL_H
