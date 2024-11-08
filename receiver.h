#ifndef RECEIVER_H
#define RECEIVER_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QCoreApplication>
#include <QDebug>

class Receiver: public QObject
{
    Q_OBJECT
private:
    QSerialPort *serial_port;
public:
    Receiver() {};
    Receiver(QString com_name);

    void setSerialPort(QString com_name);

    QByteArray connectPort();

    QSerialPort* getSerialPort() { return serial_port; };
};

#endif // RECEIVER_H
