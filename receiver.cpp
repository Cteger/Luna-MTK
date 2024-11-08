#include "receiver.h"

Receiver::Receiver(QString com_name)
{
    serial_port = new QSerialPort(this);
    setSerialPort(com_name);
}

void Receiver::setSerialPort(QString com_name)
{
    serial_port->setPortName(com_name);
    serial_port->setBaudRate(QSerialPort::Baud19200);
    serial_port->setDataBits(QSerialPort::Data8);
    serial_port->setParity(QSerialPort::NoParity);
    serial_port->setStopBits(QSerialPort::OneStop);
    serial_port->setFlowControl(QSerialPort::NoFlowControl);
}

QByteArray Receiver::connectPort()
{
    //connect(serial_port, SIGNAL(readyRead()), this, SLOT(readData));

    if (serial_port->open(QSerialPort::ReadWrite))
    {
        return serial_port->readAll();
    }
    else
    {
        qDebug() << "Последовательный порт не подключен.";
    }
}
