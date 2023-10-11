
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>
pid_t a =-1; 

void signalReceived(int signum){
    // if(a != 0){
    //     // printf("father on signal here\n");
    //     return;
    // }
    char myString[99] = {'\0'};

    int r = scanf("%s", myString); 
    // printf("my input %s\n", myString);
    r != 1 ? exit(0) : sleep(0); 
    getchar();
    // printf("Recebi %d\n", signum);
    // printf("\npid return signal %d\n", a);

    int hasError = 0; 
    switch (signum)
    {
    case SIGUSR1/* constant-expression */:
        hasError = strcmp(myString, "Igor3k") != 0 ? 1 : 0; 
        break;
        
    case SIGUSR2/* constant-expression */:
        hasError = strcmp(myString, "Monark") != 0 ? 1 : 0; 
        break;
    case SIGINT/* constant-expression */:
        hasError = strcmp(myString, "Con1") != 0 ? 1 : 0; 
        break;
    case SIGTERM/* constant-expression */:
        hasError = strcmp(myString, "Con2") != 0 ? 1 : 0; 
        break;
    case SIGALRM/* constant-expression */:
        hasError = strcmp(myString, "Silencio") != 0 ? 1 : 0; 
 
    default:
        break;
    }
    if(hasError == 1){
        printf("Erro\n");
        kill(getppid(),SIGALRM);
        // raise(SIGALRM);
    }
    else{
        printf("Certo\n"); 
    }
    
    return; 

    // return;
    // SIGUSR1 - câmera do Igor3k
    // SIGUSR2 - câmera do Monark
    // SIGINT - câmera do Convidado 1
    // SIGTERM - câmera do Convidado 2
    // SIGALRM - câmera geral
}
// void mano(){
//     printf("asdasds\n"); 
// }

int main(int argc, char **argv){
    a = fork(); 

    signal(SIGINT  , signalReceived);
    signal(SIGUSR1 , signalReceived);
    signal(SIGALRM , signalReceived);
    signal(SIGUSR2 , signalReceived);
    signal(SIGTERM , signalReceived);
    // if(!a){    
    //     // printf("PID - %ld\n", getpid()); 
    // }

    // printf("return is %d\nppid is %d\nmy pid is: %d\n" , a, getppid(), getpid());
    while(1)
        pause();

    return 0; 
}