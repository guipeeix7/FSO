#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
int signalsReceived = 0; 


void childProcess(){

    // printf("child\n");
    pid_t a = fork();
    // return; 
    if(a == 0){
        // printf("child here\n"); 
        exit(0);
        // return; 
    }
}

void killZ(){
    // printf("killed\n");

    int childReturn; 
    wait(&childReturn);
    // exit(0);
}

void end(){
    exit(0);
}

int main(){
    // printf("hellow there\n");
    // printf("PID - %d\n", getpid()); 
    signal(SIGUSR1, childProcess);
    signal(SIGUSR2, childProcess);
    pause();
    signal(SIGUSR1, killZ);
    signal(SIGUSR2, killZ);
    pause();
    signal(SIGUSR1, end);
    signal(SIGUSR2, end);


    while(1)
        pause();
    return 0;
}
