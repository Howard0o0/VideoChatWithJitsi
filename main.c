#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int iRet;
    FILE *fp; 

    iRet = system("firefox  https://meet.jit.si/401 &");
    // printf("iRet : %d \n",iRet);

    sleep(15);

    system("pkill firefox");
    printf("close \n");

    return 0;
}
