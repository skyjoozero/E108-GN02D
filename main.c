#include <stdio.h>
#include "gps.h"

int main() {
//    systemReboot("4", "2");
//    ereaseAuxiliaryInform();
//    lowPowerMode("0");
//    setMessageInterval("1000");
//    periodicLowPowerMode("8", "", "");
    periodicLowPowerMode("1", "5000", "8000");
    return 0;

}
