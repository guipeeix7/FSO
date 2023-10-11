#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t posix;

void *thread(){
    printf("entered\n");
    
    sem_wait(&posix); //0
    // sem_wait(&posix); //0

    printf("entered\n");
    sem_post(&posix); //1
    // sem_wait(&posix); 
    printf("entered again?\n"); 
    sem_wait(&posix); //0 
    printf("entered again and agAAIN ?\n");
    sem_wait(&posix); //Trava
    printf("entered again and agAAIN ?\n");
    sem_wait(&posix); 

    return NULL;
}

int main(){
    sem_init(&posix, 0, 1);
    pthread_t t1;  
    pthread_create(&t1, NULL, thread, NULL);

    pthread_exit(&t1);
}   