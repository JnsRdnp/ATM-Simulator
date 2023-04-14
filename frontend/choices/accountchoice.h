#ifndef ACCOUNTCHOICE_H
#define ACCOUNTCHOICE_H

#include <QWidget>

namespace Ui {
class AccountChoice;
}

class AccountChoice : public QWidget
{
    Q_OBJECT

public:
    explicit AccountChoice(QWidget *parent = nullptr);
    ~AccountChoice();

private:
    Ui::AccountChoice *ui;
};

#endif // ACCOUNTCHOICE_H
