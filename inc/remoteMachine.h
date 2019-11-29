#ifndef __REMOTEMACHINE_H
#define __REMOTEMACHINE_H

typedef struct remoteMachine
{
    char *remoteID;
    void (*videoOn)(struct remoteMachine *this);
    void (*videoOff)(struct remoteMachine *this);
}remoteMachine_t;


remoteMachine_t *newRemoteMachine(char *remoteId);


static void videoOn(struct remoteMachine *this);
static void videoOff(struct remoteMachine *this);

#endif