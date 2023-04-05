#include "pininterface.h"

PINInterface::PINInterface()
{
    objectPINWindow=new PINWindow;
}

QString PINInterface::getLoginResponse() const
{
    return loginResponse;
}

void PINInterface::setLoginResponse(const QString &newLoginResponse)
{
    loginResponse = newLoginResponse;
}

void PINInterface::openLogin()
{
    connect(objectPINWindow, SIGNAL(httpResponseReady),
            this, SLOT(loginReadySlot()));
    objectPINWindow->exec();
}

void PINInterface::loginReadySlot()
{
    loginResponse=objectPINWindow->getHttpResponse();
    emit loginReady();
}

