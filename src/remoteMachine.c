#include "remoteMachine.h"
#include "stdlib.h"
#include "mqtt.h"
#include <MQTTAsync.h>
#include <MQTTClient.h>

static void videoOn(struct remoteMachine *this);
static void videoOff(struct remoteMachine *this);
static void freeRemoteMachine(struct remoteMachine *this);

remoteMachine_t *newRemoteMachine(char *remoteId)
{
    remoteMachine_t *ptNewRemoteMachine = (remoteMachine_t *)malloc(sizeof(remoteMachine_t));
    ptNewRemoteMachine->remoteID = remoteId;
    ptNewRemoteMachine->videoOn = videoOn;
    ptNewRemoteMachine->videoOff = videoOff;
    ptNewRemoteMachine->freeRemoteMachine = freeRemoteMachine;

    return ptNewRemoteMachine;
}

static void videoOn(struct remoteMachine *this)
{
    char *pcTopic = (char *)calloc(strlen(this->remoteID) + strlen("/videoControl") + 1 , sizeof(char));
    strcat(pcTopic,this->remoteID);
    strcat(pcTopic,"/videoControl");

    char *pcCmd = "on";

    mqtt_client_publish(pcTopic, 2, pcCmd, strlen(pcCmd));
    free(pcTopic);
}


static void videoOff(struct remoteMachine *this)
{
    char *pcTopic = (char *)calloc(strlen(this->remoteID) + strlen("/videoControl") + 1 , sizeof(char));
    strcat(pcTopic,this->remoteID);
    strcat(pcTopic,"/videoControl");

    char *pcCmd = "off";

    mqtt_client_publish(pcTopic, 2, pcCmd, strlen(pcCmd));
    free(pcTopic);
}

static void freeRemoteMachine(struct remoteMachine *this)
{
    free(this);
}
