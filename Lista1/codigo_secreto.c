#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>

int signals[3] = {0,0,0};

void signalReceived(int signum){
    printf("Recebi %d\n", signum);

    signals[3] = signals[2]; 
    signals[2] = signals[1]; 
    signals[1] = signals[0]; 
    signals[0] = signum;

    if(signals[2] == SIGINT && signals[1] == SIGUSR2 && signals[0] == SIGTERM){
        printf("Senha acionada\n");
        return; 
    }
    else if(signals[3] == SIGINT && signals[2] == SIGUSR2 && signals[1] == SIGTERM && signals[0] == SIGUSR1){
        printf("Tchau\n");
        exit(0); 
    }
    return; 
}


int main(int argc, char **argv){
    signal(SIGINT, signalReceived);
    signal(SIGUSR1, signalReceived);
    signal(SIGUSR2 , signalReceived);
    signal(SIGTERM , signalReceived);
    // printf("this is the return -> %d \n", (sig_t)sig); 
    // printf("%ld - %ld\n\n", (long)getpid(), (long)getppid());
    // printf("PID - %ld\n", getpid()); 

    // while(true == true){
    //     // printf("%ld Gonna rest a little...\n", getpid()); 
    //     sleep(1); 
    // }
    // wait()
    while(1)
        pause();

    return 0; 
}