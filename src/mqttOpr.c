#include "mqttOpr.h"
#include "stdlib.h"
#include <MQTTAsync.h>
#include <MQTTClient.h>

mqttOpr_t *newMqttOpr_t(void)
{
    mqttOpr_t *ptNewMqttOpr = (mqttOpr_t *)malloc(sizeof(mqttOpr_t));
    ptNewMqttOpr->mqttClient = malloc(sizeof())

    return ptNewMqttOpr;
}

