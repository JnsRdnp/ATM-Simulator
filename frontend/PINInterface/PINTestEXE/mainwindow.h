#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pininterface.h"
#include "pinwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnPinLogin_clicked();
    void loginReadySlot();
private:
    Ui::MainWindow *ui;
    PINInterface *objPINInterface;
};
#endif // MAINWINDOW_H
