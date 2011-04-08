#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct my_msgbuf 
{
    long mtype;
    char mtext[200];
};
int main(void)
{
    struct my_msgbuf buf;
    int msqid;
    key_t key;
    if ((key = ftok("/home/bharath", 'B')) == -1) 
    {
        /* same key as kirk.c */
        perror("ftok");
        exit(1);
    }
    if ((msqid = msgget(key, 0644| IPC_CREAT)) == -1) 
    {
        /* connect to the queue */
        perror("msgget");
        exit(1);
    }
    printf("spock: ready to receive messages, captain.\n");

    for(;;) 
    { /* Spock never quits! */
        if (msgrcv(msqid, &buf, sizeof(buf.mtext), 2, IPC_NOWAIT) == -1) 
        {
            if (errno == ENOMSG)
            {
                usleep(10*1000);
                continue;
            }
            printf("%d\n", errno);
            perror("msgrcv");
            exit(1);
        }
        printf("Out of msgrcv\n");
        printf("spock: \"%s\"\n", buf.mtext);
    }

    printf("Removing msgqueue\n");
    if (msgctl(msqid, IPC_RMID, NULL) == -1)
    {
        perror("msgctl");
        exit(1);
    }
    printf("Removed msgqueue\n");
    return 0;
}

