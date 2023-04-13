#ifndef PINCODE_H
#define PINCODE_H

#include "pincodedll_global.h"
#include <QDialog>
#include <QDebug>

namespace Ui {
class pincode;
}

class PINCODEDLL_EXPORT pincode : public QDialog
{
    Q_OBJECT

public:
    explicit pincode(QWidget *parent = nullptr);
    ~pincode();
signals:
    void sendPin(short);
private slots:
    void on_btnPin_clicked();

private:
    Ui::pincode *ui;
};

#endif // PINCODE_H
