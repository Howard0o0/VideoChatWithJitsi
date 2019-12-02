#ifndef __REMOTEMACHINE_H
#define __REMOTEMACHINE_H

typedef struct remoteMachine
{
    char *remoteID;
    void (*videoOn)(struct remoteMachine *this);
    void (*videoOff)(struct remoteMachine *this);
    void (*freeRemoteMachine)(struct remoteMachine *this);
}remoteMachine_t;


remoteMachine_t *newRemoteMachine(char *remoteId);




#endif