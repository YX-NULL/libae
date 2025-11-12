#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../src/ae.h"

#define BUFF_SIZE 512

void freeClientData(struct aeEventLoop *eventLoop, void *clientData)
{
    if(NULL != clientData)
        free(clientData);
}

int print(struct aeEventLoop *loop, long long id, void *clientData)
{
    printf("event %lld - %s\n", id, (const char *)clientData);
    return -1;
}

void beforeTime(struct aeEventLoop *loop)
{
    printf("[%ld]beforeTime",time(NULL));
}


void afterTime(struct aeEventLoop *loop)
{
    printf("[%ld]afterTime",time(NULL));
}

int main(void)
{
    aeEventLoop *loop = aeCreateEventLoop(10);
    int i;
    for (i = 1; i < 10; i ++) {
        char *eventData = calloc(BUFF_SIZE, sizeof(char));
        if (NULL != eventData)
        {
            sprintf(eventData, "Hello World %d", i);
            aeCreateTimeEvent(loop, i*2000, print, eventData, freeClientData);
        }
    }

    aeSetBeforeSleepProc(loop, beforeTime);
    aeSetAfterSleepProc(loop, afterTime);

    aeMain(loop);
    aeDeleteEventLoop(loop);
    return 0;
}
