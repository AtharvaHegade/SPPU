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
    

    d->flag = 0; 
    printf("Enter a string: ");
    gets(d->str);
    d->flag = 1; 

    while (d->flag != -1) { 
        printf("waiting\n");
        sleep(2);
    }

  
    shmdt(d);
    shmctl(shmid, IPC_RMID , NULL);

    return 0; 
}

