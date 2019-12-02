#include "mqtt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "localOpr.h"
#include "remoteMachine.h"
#include <unistd.h>

int main(void)
{
    // int iRet;
    // FILE *fp; 

    // iRet = system("firefox  https://meet.jit.si/401 &");
    // // printf("iRet : %d \n",iRet);

    // sleep(15);

    // system("pkill firefox");
    // printf("close \n");

    remoteMachine_t *pt_remoteLab = newRemoteMachine("lab");

    /* 0. init */
    mqttInit();

    /* 1. Remote Video on */
    pt_remoteLab->videoOn(pt_remoteLab);

    /* 2. Open VideoChat App */

    /* 3. wait till end indication */
    sleep(20);

    /* 4. Remote Video off */
    pt_remoteLab->videoOff(pt_remoteLab);
    pt_remoteLab->freeRemoteMachine(pt_remoteLab);

    /* 5. VideoChat app off */
    sleep(3);

    return 0;
}
