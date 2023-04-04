#ifndef SALDOUI_H
#define SALDOUI_H

#include <QDialog>

namespace Ui {
class saldoUI;
}

class saldoUI : public QDialog
{
    Q_OBJECT

public:
    explicit saldoUI(QWidget *parent = nullptr);
    ~saldoUI();

public slots:
    void takaisinClickHandler();

private:
    Ui::saldoUI *ui;
};

#endif // SALDOUI_H
