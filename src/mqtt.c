#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <MQTTAsync.h>
#include <MQTTClient.h>
#include <pthread.h>
#include "mqtt.h"
#include "localOpr.h"

#define ADDRESS     "tcp://101.132.152.51:1883"
#define CLIENTID    "labMqttClient"
#define TOPIC       "mqtt"
#define PAYLOAD     "Hello World!"
#define QOS         1
#define TIMEOUT     10000L

static MQTTClient client = NULL;
volatile MQTTClient_deliveryToken deliveredtoken;
pthread_t threadId_msgParse;


static void threadHandlerMsgParse(void *pThreadHandlerArg);

void delivered(void *context, MQTTClient_deliveryToken dt)
{
    // mqtt Qos is 2, no need to confirm
}

int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    mqttMsg_t T_mqttMsg;

    T_mqttMsg.topic = (char *)malloc(strlen(topicName) + 1);
    T_mqttMsg.payload = (char *)malloc(strlen(message->payload) + 1);
    strcpy(T_mqttMsg.topic,topicName);
    strcpy(T_mqttMsg.payload,(char *)message->payload);

    /* create a thread to parse msg */    
    pthread_create(&threadId_msgParse, NULL, (void *)threadHandlerMsgParse, (void*)&T_mqttMsg );
    pthread_join (threadId_msgParse, NULL);

    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);

    return 1;
}

static void threadHandlerMsgParse(void *pThreadHandlerArg)
{
    mqttMsg_t *ptMqttMsg = (mqttMsg_t *)pThreadHandlerArg;
    printf("topic: %s, payload: %s \n",ptMqttMsg->topic,ptMqttMsg->payload);

    if( strstr(ptMqttMsg->topic,"videoControl") != 0)
    {
        if ( strcmp(ptMqttMsg->payload,"on") == 0 )
        {
            localVideoOn();
        }
        else if ( strcmp(ptMqttMsg->payload,"off") == 0 )
        {
            localVideoOff();
        }
        
    }  

    free(ptMqttMsg->topic);
    free(ptMqttMsg->payload);
}

void connlost(void *context, char *cause)
{
    localVideoOff();
}

int mqtt_client_publish(char *top, int qos, char *msg, int len)
{
    MQTTClient_deliveryToken token;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;

    if (client == NULL)
        return -1;

    pubmsg.payload = msg;
    pubmsg.payloadlen = len;
    pubmsg.qos = qos;
    pubmsg.retained = 0;
    deliveredtoken = 0;
    MQTTClient_publishMessage(client, top, &pubmsg, &token);
    return 0;
}

int mqtt_client_subscribe(char *top, int qos)
{
    if (client == NULL)
	return -1;

    MQTTClient_subscribe(client, top, qos);
    return 0;
}

int mqtt_client_open()
{
    int rc;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
   
    MQTTClient_create(&client, ADDRESS, CLIENTID,  MQTTCLIENT_PERSISTENCE_NONE, NULL);
    MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered);

    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        return -1;
    }
    printf("Success to connect!\n");
    return 0;
}


int mqttInit(void)
{
    

    if( (mqtt_client_open() != 0) || (mqtt_client_subscribe("lab/#", 2) != 0) )
    {
        return -1;
    }
    
    return 0;
}

int mqttTest(void)
{
    char *str = "hello world!";

    mqtt_client_publish(TOPIC, QOS, str, strlen(str));
    sleep(1);

    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    
    return 0;
}