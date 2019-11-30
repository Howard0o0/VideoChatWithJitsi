
#include "localOpr.h"
#include <stdio.h>
#include <stdlib.h>


void localVideoOn(void)
{
    int iRet;

    iRet = system("firefox  https://meet.jit.si/401 &");
    if(iRet == -1)
    {
        printf("open firefox failed! \n");
        return;
    }
    printf("localVideoOn \n");
}


void localVideoOff(void)
{
    int iRet;

    iRet = system("pkill firefox");
    if(iRet == -1)
    {
        printf("close firefox failed! \n");
        return;
    }

    printf("localVideoOff \n");
}