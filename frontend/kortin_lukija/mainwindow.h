#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QtSerialPort/QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void openSerialPort();

private slots:
    void ReadSignal_clicked();
    void StopSignal_clicked();

private:
    Ui::MainWindow *ui;
    QString cardID;
    QSerialPort *serial;
    void closeSerialPort();
    void readSerialPort();
};
#endif // MAINWINDOW_H
