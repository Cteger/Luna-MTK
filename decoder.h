#ifndef DECODER_H
#define DECODER_H

#include <iostream>
#include "lunadata.h"
#include <QSerialPort>
#include <QDebug>

class Decoder : public LunaData
{
public:
    Decoder() {};

    void decodeData(const QByteArray *data, const quint8 STARTBYTE); // декодировать полученные данные.
    float decodeAngle(const QByteArray &byte0, const QByteArray &byte1);
    bool checkLRC(const QByteArray *data);

    void printData();

};

#endif // DECODER_H
