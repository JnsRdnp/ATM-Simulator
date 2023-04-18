#ifndef CARDCHOICE_H
#define CARDCHOICE_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class CardChoice;
}

class CardChoice : public QDialog
{
    Q_OBJECT

public:
    explicit CardChoice(QWidget *parent = nullptr);
    ~CardChoice();

signals:
    void cardChoice(QString);

private slots:
    void choiceHandler();

private:
    Ui::CardChoice *ui;
};

#endif // CARDCHOICE_H
