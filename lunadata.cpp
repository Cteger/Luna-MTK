#include "lunadata.h"

LunaData::LunaData(int receiver_address, bool mode, bool alpha_reliability, bool beta_reliability, float alpha_stabilization, float alpha_BUO, float alpha_delta, float psi_0, float beta_stabilization, float beta_delta, int LRC)
{
    setMode(mode);

    setAlphaReliability(alpha_reliability);
    setBetaReliability(beta_reliability);

    setAlphaStabilization(alpha_stabilization);
    setAlphaBUO(alpha_BUO);
    setAlphaDelta(alpha_delta);

    setPsi0(psi_0);

    setBetaStabilization(beta_stabilization);
    setBetaDelta(beta_delta);

    setLRC(LRC);
}
