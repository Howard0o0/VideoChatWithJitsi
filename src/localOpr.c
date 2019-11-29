
#include "localOpr.h"


void localVideoOn(void)
{
    system("firefox  https://meet.jit.si/401 &");
}


void localVideoOff(void)
{
    system("pkill firefox");
}