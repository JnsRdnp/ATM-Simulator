#ifndef OMATTIEDOT_H
#define OMATTIEDOT_H

#include <QDialog>

namespace Ui {
class omatTiedot;
}

class omatTiedot : public QDialog
{
    Q_OBJECT

public:
    explicit omatTiedot(QWidget *parent = nullptr);
    ~omatTiedot();

private:
    Ui::omatTiedot *ui;
};

#endif // OMATTIEDOT_H
