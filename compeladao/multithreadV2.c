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
int k = 0; 
void *thread2(){
    while(1){
        sem_post(&semT1);k++;
        printf("t2 at service from thread %d\n", pthread_self());
        sleep(1);
        sem_wait(&semT1);

        if(k%10 == 0){
            k++;
            return 0; 
        }
    }
    return NULL;
}

int main(){
    sem_init(&semT1, 0, 0);
    // sem_init(&semT2, 0, 1);
    // pthread_t t1, t2;
    sem_post(&semT1);  
    sem_post(&semT1);  
    sem_post(&semT1);  
    int semValue = 0; 
    sem_getvalue(&semT1, &semValue);

    printf("%d\n\n", semValue);

    return 1; 
    int nClients = 2; 
    pthread_t tClients[nClients];
    // pthread_create(&t1, NULL, thread1, NULL);
    // pthread_create(&t2, NULL, thread2, NULL);
    for(int i = 0 ; i < nClients ; i++){
        pthread_create(&tClients[i], NULL, thread2, NULL);    
    }
    sleep(3);
    // sem_post(&semT1);


    for(int i = 0 ; i < nClients ; i++){
        pthread_exit(NULL);
    }
    // pthread_exit(&t2);
}   