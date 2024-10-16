#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct data {
    int flag;
    char str[100];
};

int main() {
    key_t key = ftok("abc.txt", 'A');
    

    int shmid = shmget(key, sizeof(struct data), 0777 | IPC_CREAT);
   

    struct data *d = shmat(shmid, NULL, 0);
    

    while (d->flag != 1) {
        printf("Waiting\n");
        sleep(1);
    }

    printf("Received Data: %s", d->str) ;
    printf("\n");

    d->flag = -1;

    shmdt(d);

    return 0;
}

