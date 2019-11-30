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

    /* 0. init */
    mqttInit();

    /* 1. Remote Video on */

    /* 2. Open VideoChat App */

    /* 3. wait till end indication */

    /* 4. Remote Video off */

    /* 5. VideoChat app off */

    while (1)
    {
        sleep(10);
    }
    

    return 0;
}
