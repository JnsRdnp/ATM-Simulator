#ifndef SIGNOUTTIMERINTERFACE_H
#define SIGNOUTTIMERINTERFACE_H

#include "signoutTimerDLL_global.h"
#include "signouttimerengine.h"

#include <QDebug>
#include <QDialog>

namespace Ui {
class SingoutTimerInterface;
}

class SIGNOUTTIMERDLL_EXPORT SignoutTimerInterface : public QDialog
{
    Q_OBJECT

public:
    explicit SignoutTimerInterface(QWidget *parent = nullptr);
    ~SignoutTimerInterface();
public slots:
    void agreeButtonHandler();
    void disagreeButtonHandler();
    void newJsonWebTokenHandler(QByteArray);
signals:
    void newJsonWebToken(QByteArray);

private:
    Ui::SingoutTimerInterface *ui;
    SignoutTimerEngine *Engine;
};

#endif // SIGNOUTTIMERINTERFACE_H
