#ifndef LUNADATA_H
#define LUNADATA_H

class LunaData
{
private:
    int receiver_address; // адрес получателя.
    //int packet_id; // идентификатор пакета.
    bool mode; // режим работы. 0 - рабочий, 1 - тестовый.

    bool alpha_reliability; // надежность Alpha. 0 - не достоверный, 1 - достоверный.
    bool beta_reliability;

    float alpha_stabilization; // стабилизация Alpha.
    float alpha_BUO; // значение Alpha BUO.
    float alpha_delta; // текущая погрешность.

    float psi_0; // значение осредненного текущего угла дифферента осевой линии ПУ корабля.

    float beta_stabilization; // задаваемый угол компенсации.
    float beta_delta; // текущая погрешность.

    int LRC; // контрольная сумма (LRC).

public:
    LunaData() {};
    LunaData(int receiver_address, bool mode, bool alpha_reliability, bool beta_reliability, float alpha_stabilization, float alpha_BUO, float alpha_delta, float psi_0, float beta_stabilization, float beta_delta, int lrc);

    void setMode(bool i) { mode = i; };
    bool getMode() { return mode; };

    void setAlphaReliability(bool i) { alpha_reliability = i; };
    bool getAlphaReliability() { return alpha_reliability; };

    void setBetaReliability(bool i) { beta_reliability = i; };
    bool getBetaReliability() { return beta_reliability; };

    void setAlphaStabilization(float i) { alpha_stabilization = i; };
    float getAlphaStabilization() { return alpha_stabilization; };

    void setAlphaBUO(float i) { alpha_BUO = i; };
    float getAlphaBUO() { return alpha_BUO; };

    void setAlphaDelta(float i) { alpha_delta = i; };
    float getAlphaDelta() { return alpha_delta; };

    void setPsi0(float i) { psi_0 = i; };
    float getPsi0() { return psi_0; };

    void setBetaStabilization(float i) { beta_stabilization = i; };
    float getBetaStabilization() { return beta_stabilization; };

    void setBetaDelta(float i) { beta_delta = i; };
    float getBetaDelta() { return beta_delta; };

    void setLRC(int i) { LRC = i; };
    int getLRC() { return LRC; };
};

#endif // LUNADATA_H
