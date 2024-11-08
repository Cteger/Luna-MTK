#include "decoder.h"

void Decoder::decodeData(const QByteArray *data, const quint8 STARTBYTE)
{
    if (data->size() == 15)
    {
        if (data[0] == STARTBYTE)
        {
            if (data->at(1) & 1) { setMode(true); } else { setMode(false); }
            if (data->at(1) & 1 << 1) { setAlphaReliability(true); } else { setAlphaReliability(false); }
            if (data->at(1) & 1 << 2) { setBetaReliability(true); } else { setBetaReliability(false); }

            setAlphaStabilization(decodeAngle(data[2], data[3]));
            setAlphaBUO(decodeAngle(data[4], data[5]));
            setAlphaDelta(decodeAngle(data[6], data[7]));

            setPsi0(decodeAngle(data[8], data[9]));

            setBetaStabilization(decodeAngle(data[10], data[11]));
            setBetaDelta(decodeAngle(data[12], data[13]));

            setLRC(checkLRC(data));
        }
        else
        {
            qDebug() << "Ошибка - неверный адресс.";
        }
    }
    else
    {
        qDebug() << "Приняты не корректные данные.";
    }
}


float Decoder::decodeAngle(const QByteArray &byte0, const QByteArray &byte1)
{
    int a = 0;
    float result = 360 / 32768;
    if (byte1[0] & 1 << 7)
    {
        for (int i = 0; i < 16; i++)
        {
            a++;
            a <<= 1;
        }
    }

    for (int i = 7; i >= 0; i++)
    {
        if (!(byte1[0] & 1 << i)) { a += 1; }

        a <<= 1;
    }
    for (int i = 7; i >= 0; i++)
    {
        if (!(byte0[0] & 1 << i)) { a += 1; }

        a <<= 1;
    }

    return a * result;
}

bool Decoder::checkLRC(const QByteArray *data)
{
    QByteArray byte_sum;

    for (int i = 0; i < 14; i++)
    {
        byte_sum += data[i];
    }

    if (byte_sum == data[14]) { return true; } else { return false; }
}

void Decoder::printData()
{
    std::cout << "mode - ";
    if (getMode()) { std::cout << "test" << std::endl; }
    else { std::cout << "work" << std::endl; }

    std::cout << "alpha_reliability - ";
    if (getAlphaReliability()) { std::cout << "true" << std::endl; }
    else { std::cout << "false" << std::endl; }

    std::cout << "beta_reliability - ";
    if (getBetaReliability()) { std::cout << "true" << std::endl; }
    else { std::cout << "false" << std::endl; }

    std::cout << "alpha_stabilization - ";
    std::cout << getAlphaStabilization() << std::endl;

    std::cout << "alpha_BUO - ";
    std::cout << getAlphaBUO() << std::endl;

    std::cout << "alpha_delta - ";
    std::cout << getAlphaDelta() << std::endl;

    std::cout << "psi_0 - ";
    std::cout << getPsi0() << std::endl;

    std::cout << "beta_stabilization - ";
    std::cout << getBetaStabilization() << std::endl;


    std::cout << "beta_delta - ";
    std::cout << getBetaDelta() << std::endl;

    std::cout << "LRC - ";
    std::cout << getLRC() << std::endl;
}
