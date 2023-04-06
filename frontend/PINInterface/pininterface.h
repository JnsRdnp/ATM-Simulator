#ifndef PININTERFACE_H
#define PININTERFACE_H

#include "PINInterface_global.h"
#include "pinwindow.h"

class PININTERFACE_EXPORT PINInterface : public QObject
{
    Q_OBJECT
public:
    PINInterface();
    QString getLoginResponse() const;
    void setLoginResponse(const QString &newLoginResponse);
    void openLogin();

private slots:
    void loginReadySlot();
signals:
    void loginReady();
private:
    QString loginResponse;
    PINWindow *objectPINWindow;
};

#endif // PININTERFACE_H
