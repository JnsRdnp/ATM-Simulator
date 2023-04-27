#ifndef WITHDRAWDLL_H
#define WITHDRAWDLL_H

#include "withdrawDLL_global.h"
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
    explicit withdrawdll(QWidget *parent = nullptr, int inAccountID = 0, bool inIsCardCredit = false, QString inBaseUrl="",QByteArray inJwt = "");
    ~withdrawdll();

private slots:
    void tenEuroClickHandler();
    void twentyEuroClickHandler();
    void fiftyEuroClickHandler();
    void hundredEuroClickHandler();
    void returnHandler();

    void withdrawFailSlot();

private:
    WithdrawDLLEngine * Engine;
    Ui::withdrawdll *ui;

signals:
    void localMenuTimerResetSignal();
};

#endif // WITHDRAWDLL_H
