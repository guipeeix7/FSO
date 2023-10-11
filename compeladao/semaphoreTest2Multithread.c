#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t semT1;
sem_t semT2;

void *thread1(){
    
    while(1){
        sem_wait(&semT1);

        printf("t1 at service\n");
        sem_post(&semT2);

        sleep(1);

    }


    return NULL;
}

void *thread2(){
    while(1){
        sem_post(&semT1);
        printf("t2 at service\n");
        sleep(1);
        sem_wait(&semT2);


    }
    return NULL;
}

int main(){
    sem_init(&semT1, 0, 0);
    sem_init(&semT2, 0, 1);
    pthread_t t1, t2;  
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);



    pthread_exit(&t1);
    pthread_exit(&t2);
}   