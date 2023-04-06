#include "withdrawdllengine.h"

WithdrawDLLEngine::WithdrawDLLEngine(QWidget *parent) : QDialog(parent)
{
    qDebug() << "Create DLL Engine";
}


WithdrawDLLEngine::~WithdrawDLLEngine()
{
    qDebug() << "Destroy DLL Engine";
}

void WithdrawDLLEngine::withdraw(float num)
{

}
