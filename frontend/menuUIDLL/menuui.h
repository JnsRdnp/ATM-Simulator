#ifndef MENUUI_H
#define MENUUI_H

#include <QDialog>
#include "menuUIDLL_global.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QTimer>

namespace Ui {
class menuUI;
}

class MENUUIDLL_EXPORT menuUI : public QDialog
{
    Q_OBJECT

public:
    explicit menuUI(QWidget *parent = nullptr);
    ~menuUI();

public slots:
    void saldoClickHandler();
    void nostoClickHandler();
    void tiliClickHandler();
    void kirjauduUloshandler();
    void timeoutHandler();

private slots:
    void loginSlot (QNetworkReply *reply);

private:
    Ui::menuUI *ui;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray responseData;
    QTimer * ptimer();
    int aika = 0;
    //saldoUI * pSaldoUI;
    //nostoUI * pnostoUI;
    //tiliUI * ptiliUI;
};

#endif // MENUUI_H
