#ifndef PININTERFACE_H
#define PININTERFACE_H

#include "PINInterface_global.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class PININTERFACE_EXPORT PINInterface
{
public:
    PINInterface();
    ~PINInterface();
private:
    void postCredentials(QNetworkReply *reply);
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // PININTERFACE_H
