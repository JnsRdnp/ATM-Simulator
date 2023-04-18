#ifndef ERRORSCREEN_H
#define ERRORSCREEN_H

#include <QDialog>

namespace Ui {
class ErrorScreen;
}

class ErrorScreen : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorScreen(QWidget *parent = nullptr);
    ~ErrorScreen();
signals:
    void okClickedSignal();

private slots:
    void okClickHandler();

private:
    Ui::ErrorScreen *ui;
};

#endif // ERRORSCREEN_H
