#ifndef NOSTOUI_H
#define NOSTOUI_H

#include <QDialog>

namespace Ui {
class nostoUI;
}

class nostoUI : public QDialog
{
    Q_OBJECT

public:
    explicit nostoUI(QWidget *parent = nullptr);
    ~nostoUI();

public slots:
    void takaisinClickHandler();

private:
    Ui::nostoUI *ui;
};

#endif // NOSTOUI_H
