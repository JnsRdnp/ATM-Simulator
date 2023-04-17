#ifndef ACCOUNTCHOICE_H
#define ACCOUNTCHOICE_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDebug>
#include <QListWidget>


namespace Ui {
class AccountChoice;
}

class AccountChoice : public QDialog
{
    Q_OBJECT

public:
    explicit AccountChoice(QWidget *parent = nullptr);
    ~AccountChoice();
    void setQJsonArray(QJsonArray);
public slots:
    void selectHandler(QListWidgetItem *item = nullptr);

signals:
    void selectedAccountSender(QString);

private:
    Ui::AccountChoice *ui;
};

#endif // ACCOUNTCHOICE_H

