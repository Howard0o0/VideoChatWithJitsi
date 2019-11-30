#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <MQTTAsync.h>
#include <MQTTClient.h>

typedef struct mqttMsg_strcut
{
    char *topic;
    char *payload;
}mqttMsg_t;


int mqttInit(void);

void delivered(void *context, MQTTClient_deliveryToken dt);

int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message);


void connlost(void *context, char *cause);


int mqtt_client_publish(char *top, int qos, char *msg, int len);


int mqtt_client_subscribe(char *top, int qos);


int mqtt_client_open();


int mqttTest(void);

