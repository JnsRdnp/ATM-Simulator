#ifndef CARDREADER_H
#define CARDREADER_H

#include <QDialog>
#include <QString>
#include <QtSerialPort/QSerialPort>
#include "CardReader_global.h"

namespace Ui {
class CardReader;
}

class CARDREADER_EXPORT CardReader : public QDialog
{
    Q_OBJECT

public:
    explicit CardReader(QWidget *parent = nullptr);
    ~CardReader();
    void openSerialPort();
signals:
    void RFIDSignal(QString);

public slots:
    void ReadSignal_clicked();

private:
    Ui::CardReader *ui;
    QString cardID;
    QSerialPort *serial;
    void readSerialPort();
};

#endif // CARDREADER_H
