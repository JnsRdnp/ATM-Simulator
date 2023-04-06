#ifndef WITHDRAWDLLENGINE_H
#define WITHDRAWDLLENGINE_H

#include <QDialog>
#include <QDebug>


class WithdrawDLLEngine : public QDialog
{
    Q_OBJECT
public:
    WithdrawDLLEngine(QWidget *parent = nullptr);
    ~WithdrawDLLEngine();
    void withdraw(float);
};

#endif // WITHDRAWDLLENGINE_H
