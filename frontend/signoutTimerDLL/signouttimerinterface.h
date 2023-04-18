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
    explicit SignoutTimerInterface(QWidget *parent = nullptr, QString inCardID = "", QString inPIN = "", QString IN_BASE_URL = "");
    ~SignoutTimerInterface();
    static SignoutTimerInterface* getInstance(QWidget *parent = nullptr, QString inCardID = "", QString inPIN = "", QString IN_BASE_URL = "");


public slots:
    void agreeButtonHandler();
    void disagreeButtonHandler();
    void newJsonWebTokenHandler(QByteArray);
    void restartMenuTimerHandler();
    void destroyMenuHandler();
    void closeSignoutHandler();

signals:
    void newJsonWebToken(QByteArray);
    void eliminateMenu();
    void menuTimerRestart();

private:
    Ui::SingoutTimerInterface *ui;
    SignoutTimerEngine *Engine;
    static SignoutTimerInterface* instance;


};

#endif // SIGNOUTTIMERINTERFACE_H
