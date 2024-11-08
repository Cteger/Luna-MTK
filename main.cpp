#include <QCoreApplication>
#include "receiver.h"
#include "decoder.h"
#include <QSerialPort>
#include <QSerialPortInfo>

int main(int argc, char *argv[])
{
    Receiver receiver = Receiver("com9");
    QByteArray input_B = receiver.connectPort();

    Decoder decoder;
    decoder.decodeData(&input_B, 0x1);
    decoder.printData();
}
