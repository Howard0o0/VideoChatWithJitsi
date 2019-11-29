#ifndef __MQTTOPR_H
#define __MQTTOPR_H

#include <MQTTAsync.h>
#include <MQTTClient.h>

typedef struct mqttOpr
{
    MQTTClient *mqttClient;

}mqttOpr_t;

mqttOpr_t *newMqttOpr_t(void);


#endif
