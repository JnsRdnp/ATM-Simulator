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
    void sendPin(QString);
private slots:
    void on_btnPin_clicked();
    void digit_pressed();
    void clear_pin();

private:
    Ui::pincode *ui;
    QString labelNumber;
};

#endif // PINCODE_H
