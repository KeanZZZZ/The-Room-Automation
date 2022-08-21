#include "RFcontrol.h"

RCSwitch mySwitch = RCSwitch();

void initial_RF()
{
    mySwitch.enableTransmit(12);
    mySwitch.setPulseLength(175);
}

void tonSig2()
{
    mySwitch.send(5526979,24);
}

void toffSig2()
{
    mySwitch.send(5526988,24);
}