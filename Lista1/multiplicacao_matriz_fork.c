#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>

pid_t p1 = 0, p2 = 0;
int matrixSize = 0;
int middle = 0; 

int **A,
    **B,
    **C; 

int matrixDot(int begin, int limit, int matrixSize,  int **A, int **B, int **C){ 
    // printf("child ready for the kill\n");
    for(int i = begin; i < limit ; i++){
        for(int j = 0; j < matrixSize; j++){
            // scanf(" %d", &B[i][j]);
            C[i][j] = A[i][j] * B[i][j];
            // printf("%d\n", C[i][j]);  
        }
        // printf("\n");
    }
    
}


void childAFunc(){
    printf("i am in the chaild 1\n");
    
    matrixDot(0, middle,matrixSize, A,B,C); 

    kill(getppid(),2);
    pause();
}

void childBFunc(){
    printf("i am in the chaild 2\n");

    matrixDot(middle+1, matrixSize,matrixSize, A,B,C);

    kill(getppid(),2);  
    pause();
}

int main(){
    scanf("%d" ,&matrixSize); 
    
    A = (int**) malloc(matrixSize*sizeof(int));
    B = (int**) malloc(matrixSize*sizeof(int));
    C = (int**) malloc(matrixSize*sizeof(int));

    for(int i = 0; i < matrixSize ; i++){
        A[i] = (int*) malloc(matrixSize*sizeof(int));
        B[i] = (int*) malloc(matrixSize*sizeof(int));
        C[i] = (int*) malloc(matrixSize*sizeof(int));
    }
    
    for(int i = 0 ; i < matrixSize ; i++)
        for(int j = 0 ; j < matrixSize; j++)
            scanf(" %d", &A[i][j]); 
    
    for(int i = 0 ; i < matrixSize ; i++)
        for(int j = 0 ; j < matrixSize; j++)
            scanf(" %d", &B[i][j]); 

    
    pid_t pai = getpid(); 
    p1 = fork(); 
    if(p1 > 0 ){
        p2 = fork(); 
    }
    int isFather = p1 + p2; 
    // pause();
    middle = matrixSize/2; 
    printf("My childs = %d, %d\n", p1,p2); 
    // return 1;

    
    // signal(SIGUSR1,childAFunc);
    // signal(SIGUSR2,childBFunc);

    // if(p1 == 0 && p2 == 0){
    //     printf("okey\n");
    //     // while(1);
    //     //     pause(); 
    //     // pause(); 
    //     pause();
    //     // pause(); 
    // }

    // if(p1 && p2){//father process
    //     // printf("SOKDPASDK %d %d\n", p1, p2);
    //     // sleep(2);

    //     // printf("okey %d %d\n", p1, p2);
    //     kill(p1, SIGUSR1);
    //     kill(p2, SIGUSR2); 
    //     // pause();
    //     // pause();
    //     sleep(20);
    //     // pause();
    //     printf("I CONTINUE\n");
    // }  
    // pause();




    // return 1;
    // pause();
    // pause();
    // if(!(p1 && p2)){
    //     // kill(p1,SIGUSR1);
    //     // // pause();
    //     // kill(p2,SIGUSR1);
    //     //DO father things
    // }
    // for(int i = 0 ; i < matrixSize ; i++)
    //     // for(int j = 0 ; j < matrixSize; j++)
    //         scanf("%d", &A[i][j]); 
        
}


    // for(int i = 0 ; i < matrixSize ; i++){
    //     printf("\n");
    //     for(int j = 0 ; j < matrixSize; j++)
    //         printf("%d ", B[i][j]); 
    // }

    // return 0;
    // return 0 ; 

    // if(p1 > 0 && p2 > 0){

    //     // printf("PID %d<--\n",pai);
    //     // printf("PID %d<--\n", getpid());
    //     // printf("PID %d<--\n", p1);
    //     // printf("PID %d<--\n", p2);
    //     // if(getpid() == )
    // }
    // if(p2 == 0){
    //     // for(int i = 0 ; i < matrixSize ; i++){
    //     //     printf("\n");
    //     //     for(int j = 0 ; j < matrixSize; j++)
    //     //         printf("%d ", B[i][j]); 
    //     // }
        
    //     // printf("PID p1 %d<--\n", p1);
    //     // printf("PID p2 %d<--\n", p2);
    //     printf("PID p1 %d<--\n", getpid());
    //     printf("PID p2 %d<--\n", getpid());

    // }
    // pause();

    // return 0; 

    
    // if(p2 == getpid()){
    //     //Do the trick 2
    //     printf("okey");
    // }