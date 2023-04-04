#ifndef TILIUI_H
#define TILIUI_H

#include <QDialog>

namespace Ui {
class tiliUI;
}

class tiliUI : public QDialog
{
    Q_OBJECT

public:
    explicit tiliUI(QWidget *parent = nullptr);
    ~tiliUI();

public slots:
    void takaisinClickHandler();

private:
    Ui::tiliUI *ui;
};

#endif // TILIUI_H
