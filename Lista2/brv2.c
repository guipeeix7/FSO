#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>  

/*
    Uma aproximação mais correta seria usar semáforos para a congelar as funcçoes de comparação, mas vou deixar essa pra próxima...
*/

typedef struct DLL{
    int value;    
    struct DLL *prevNodeAddress; 
    struct DLL *proxNodeAddress; 

} DLL; 


DLL *init(){
    DLL *headNode = (DLL*) malloc(sizeof(DLL));  
    headNode->proxNodeAddress = NULL; 
    headNode->prevNodeAddress = NULL; 
    return headNode; 
}

DLL *addEndList( int value, DLL *headNode){
    DLL *newNode = (DLL*) malloc(sizeof(DLL)); 
    
    if(headNode->prevNodeAddress == NULL &&  headNode->proxNodeAddress == NULL){
        newNode->prevNodeAddress = NULL; 
        headNode->prevNodeAddress = newNode; 
    }else{
        newNode->prevNodeAddress = headNode->proxNodeAddress; 
        headNode->proxNodeAddress->proxNodeAddress = newNode; 
    }
    newNode->value = value;  
    newNode->proxNodeAddress = NULL;  
    headNode->proxNodeAddress = newNode; 

    return newNode; 
}



void showList(DLL *headNode){
    DLL *temp = headNode->prevNodeAddress; 
    
    while(temp != NULL){
        printf(" value: %d\n", temp->value);
        temp = temp->proxNodeAddress; 
    }
    return; 
}

typedef struct seedVector{
    int begin; 
    int middle; 
    int end; 
    DLL *v; 
    int vSize; 
    int semente; 
}seedVector;

int geraTeste(int semente){
    for (int i = 5; i < 20; i++){
        for (int j = 1; j < 10000; j++)
            rand_r(&semente);
        printf("%d\n", rand_r(&semente) % 256);
    }
}

void *verifyRand(void *data){
    seedVector *myData = ((seedVector*) data) ;
    DLL *temp = myData->v->prevNodeAddress; 
    int seed = 0; 
    for (int i = myData->begin; i <= myData->end; i++){
        seed = i; 
        int isNotValid = 0; 

        for (int j = 0; j < myData->vSize; j++){
            for(int k = 1; k < 10000; k++){
                rand_r(&seed);
            }
            if(!(rand_r(&seed) % 256 == temp->value)){
                isNotValid = 1; 
                temp = myData->v->prevNodeAddress; 
             
                break;
            }
            temp = temp->proxNodeAddress; 
        }
        if(isNotValid == 0){
            printf("%d\n", i);
            return NULL; 
        }

    }
}

void verifyGenerated(DLL *dll, int vLenght, int ll,int lh){
    seedVector *sdVa = (seedVector*) malloc(sizeof(seedVector));
    seedVector *sdVb = (seedVector*) malloc(sizeof(seedVector));

    int middle = (lh+ll)/2;


    sdVa->v = dll;
    sdVa->begin = ll; 
    sdVa->end = middle; 
    sdVa->vSize = vLenght; 


    pthread_t t1, t2; 
    pthread_create(&t1, NULL, &verifyRand, (void*) sdVa);

    if((lh - ll) > 1){
        sdVb->v = dll;
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
    int ll = 0 , lh = 0; 
    scanf("%d %d", &ll, &lh);
    int *v = (int*) malloc(50000*sizeof(int));
    int i = 0; 
    int num = 0; 
    DLL *headNode = init();


    while(scanf(" %d", &num ) == 1){
        
        addEndList(num,headNode);
        i++;
    }
    verifyGenerated(headNode, i-1, ll , lh);
}
