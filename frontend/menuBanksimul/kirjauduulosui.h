#ifndef KIRJAUDUULOSUI_H
#define KIRJAUDUULOSUI_H

#include <QDialog>

namespace Ui {
class kirjauduUlosUI;
}

class kirjauduUlosUI : public QDialog
{
    Q_OBJECT

public:
    explicit kirjauduUlosUI(QWidget *parent = nullptr);
    ~kirjauduUlosUI();

private:
    Ui::kirjauduUlosUI *ui;
};

#endif // KIRJAUDUULOSUI_H
