#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>  

/*
    Uma aproximação mais correta seria usar semáforos para a congelar as funcçoes de comparação, mas vou deixar essa pra próxima...
*/

typedef struct seedVector{
    int begin; 
    int middle; 
    int end; 
    int *v; 
    int vSize; 
    int semente; 
}seedVector;

int geraTeste(int semente){
    // int semente = 1;
    for (int i = 5; i < 20; i++){
        for (int j = 1; j < 10000; j++)
            rand_r(&semente);
        printf("%d\n", rand_r(&semente) % 256);
    }
}

void *verifyRand(void *data){
    seedVector *myData = ((seedVector*) data) ;

    // printf("[%d]", myData->end);
    // return NULL; 
    int seed = 0; 
    for (int i = myData->begin; i <= myData->end; i++){
        seed = i; 
        int isNotValid = 0; 
        // printf("\n%d\n", i);
        // continue;

        for (int j = 0; j < myData->vSize; j++){
            for(int k = 1; k < 10000; k++){
                rand_r(&seed);
            }
            // printf("\n%d\n", i);
            // actual = rand_r(&semente) % 256;
            if(!(rand_r(&seed) % 256 == myData->v[j])){
                
                isNotValid = 1; 
                break;
            }

        }
        if(isNotValid == 0){
            printf("%d\n", i);
        }

        // printf("%d\n", rand_r(&semente) % 256);
    }
}

void verifyGenerated(int *v, int vLenght, int ll,int lh){
    seedVector *sdVa = (seedVector*) malloc(sizeof(seedVector));
    seedVector *sdVb = (seedVector*) malloc(sizeof(seedVector));

    // long number_of_processors = sysconf(_SC_NPROCESSORS_ONLN);
    // printf("NUMB PROC = %d\n", number_of_processors);
    // int interval = lh-ll;
    // sections = interval/2;
    // if(!(process % 2 == 0)) sections++; 

    int middle = (lh+ll)/2;


    sdVa->v = (void*) &v[0];
    sdVa->begin = ll; 
    // sdVa->begin = middle; 
    sdVa->end = middle; 
    sdVa->vSize = vLenght; 


    pthread_t t1, t2; 
    pthread_create(&t1, NULL, &verifyRand, (void*) sdVa);

    if((lh - ll) > 1){
        sdVb->v = (void*) &v[0];
        sdVb->begin = middle+1; 
        sdVb->end = lh; 
        sdVb->vSize = vLenght; 
        pthread_create(&t2, NULL, &verifyRand, (void*) sdVb);
        pthread_exit(NULL);

    }
    pthread_exit(NULL);
}


int main(){
    int semente;
    // printf("Digite a sua semente:\n");
    int ll = 0 , lh = 0; 
    scanf("%d %d", &ll, &lh);
    int *v = (int*) malloc(50000*sizeof(int));
    int i = 0; 
    while(scanf(" %d", &v[i++] ) == 1){
        if(i >= 50000){
            v = (int *) realloc (v, 50000 * sizeof( int)); 
        }
        // i = 0; 
    }
    // printf("[%d]",i);
    
    // for(int k = 0 ; k < i-1 ; k++){
    //     printf(" %d ", v[k]); 
    // }
    // for (int i = 0; i < 20; i++){
    // geraTeste(semente);
    verifyGenerated(v, i-1, ll , lh);
    // printf("\n %d\n", rand_r(&semente) % 256);
    // }
    // geraTeste();
}
