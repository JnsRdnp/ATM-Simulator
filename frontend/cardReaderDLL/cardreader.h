#ifndef CARDREADER_H
#define CARDREADER_H

#include <QDialog>
#include <QString>
#include <QtSerialPort/QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class CardReader; }
QT_END_NAMESPACE

class CardReader : public QDialog
{
    Q_OBJECT

public:
    CardReader(QWidget *parent = nullptr);
    ~CardReader();
    void openSerialPort();

private slots:
    void ReadSignal_clicked();

private:
    Ui::CardReader *ui;
    QString cardID;
    QSerialPort *serial;
    void readSerialPort();
};
#endif // CARDREADER_H
