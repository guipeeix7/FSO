
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>
int a = 0; 

void signalReceived(int signum){
    
    switch (signum)
    {
    case SIGUSR1/* constant-expression */:
        //hasError = strcmp(myString, "Igor3k") != 0 ? 1 : 0; 
        printf("SIGUSR1 eh para aproveitar mais um pouco\n"); 
        break;
    case SIGALRM/* constant-expression */:
        if(a < 2){
            printf("Ai que sono, quero dormir mais um pouco\n"); 
            a++; 
        }
        else{
            printf("Os incomodados que se mudem, tchau\n"); 
            exit(0);
        }
    default:
        break;
    }
    return; 
}

int main(int argc, char **argv){
    signal(SIGUSR1 , signalReceived);
    signal(SIGALRM , signalReceived);
    // printf("PID - %ld\n", getpid()); 
    while(1)
        pause();

    return 0; 
}