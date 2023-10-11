#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t semClient;
sem_t semSealer;

/**
 * mutex values:
 * -1 - freeze
 * 1 - free
 * 2 - creating tickets
 * 3 - one client is consuming ticket
 * 
*/

int randBeautyTrick = 0; 

void* client(void * );

void* sealer(void *);

//The stack
typedef struct Stack{
    struct Stack *prox;
    int key;  
}Stack; 

//Node to begin and end of stack
typedef struct HeadStack{
    Stack *head;
    Stack *tail;    
}HeadStack; 

//Init the node that will point to begin and end of my Stack
HeadStack *init(){
    HeadStack *root = (HeadStack*) malloc(sizeof(HeadStack)); 
    root->head = NULL; 
    root->tail = NULL; 
    return root;  
}

//Check if the stack is empty or not
int emptyStack(HeadStack *headStack){
    if(headStack->tail == NULL){
        printf("Sem tickets parça\n"); 
        return 1; 
    }
    return 0;
}

//Pop from the end of stack
void pop(HeadStack *headStack){
    if(headStack->tail == NULL){
        printf("Sem tickets parça\n"); 
        // sem_post(&semClient);

        return; 
    }
    
    Stack *nextAux = headStack->tail->prox;
    free(headStack->tail);
    headStack->tail = nextAux; 

    if(headStack->tail == NULL && headStack->head != NULL){
        headStack->head = NULL;
    }
    // sem_post(&semClient);

}

//Push to begin of stack
void push(HeadStack *headStack, int key){
    Stack *newNode = (Stack*) malloc(sizeof(Stack)); 
    
    newNode->key = key;
    newNode->prox = NULL;

    if(headStack->head == NULL){
        headStack->head = newNode;
        headStack->tail = newNode;
        return ; 
    }

    headStack->head->prox = newNode; 
    headStack->head = newNode; 
    return ;  
}

//Display all the stack
void showStack(HeadStack *HeadStack){
    Stack *aux = HeadStack->tail; 
    while(aux != NULL){
        printf("%d\n", aux->key); 
        aux = aux->prox; 
    }
    return; 
}

//Generate rando numbers
int generateRandon(){
    srand(time(NULL)); 
    if(randBeautyTrick > INT_MAX){
        randBeautyTrick = 0;
    }
    return randBeautyTrick++; 
    // return (rand() + randBeautyTrick++)%9999999; 
}

int main(void){
    // HeadStack *headStack = init();
    // // push(headStack, 5);
    // // push(headStack, 6);
    
    // pop(headStack); 
    // pop(headStack); 
    // pop(headStack); 

    // push(headStack, 9);
    // push(headStack, 10);
    
    // pop(headStack); 
    // pop(headStack); 
    // // pop(headStack); 
    // // pop(headStack); 
    // // pop(headStack); 
    // // pop(headStack); 
    // // pop(headStack); 
    // // pop(headStack); 
    // // pop(headStack); 
    // // push(headStack, 9999);
    // // push(headStack, 9999);
    // // pop(headStack); 
    // // pop(headStack); 

    // // showStack(headStack); 
    // printf("%d\n", headStack->tail->key); 

    // return; 
    HeadStack *headStack = init();
    sem_init(&semClient, 0,0);
    sem_init(&semSealer, 0,1);
    pthread_t tSealer;
    // push(headStack, 5);

    pthread_create(&tSealer, NULL, sealer, (void*) headStack);
    
    //Cria dois lindos clientes.
    int nClients = 4; 
    pthread_t tClients[nClients];
    // pthread_join(tSealer, NULL);
    // sleep(2);

    for(int i = 0 ; i < nClients ; i++){
        pthread_create(&tClients[i], NULL, client, (void*) headStack);    
    }

    // pthread_join(tSealer, NULL); 
    // for(int i = 0 ; i < nClients ; i++){
    //     pthread_join(tClients, NULL); 
    // }

    for(int i = 0 ; i < nClients ; i++){
        pthread_exit(&tClients[i]); 
    }
    
    pthread_exit(NULL); 
    free(headStack);

    printf("main ended\n"); 
    // return 0;

}

// push(headStack, 5);
// pop(headStack);
// printf("%ld\n", generateRandon());
// showStack(headStack); 
int tickets = 0; 

void* client(void * headStack){
    // sem_wait(&semClient);
         *headNode = (HeadStack*) headStack; 
    int auxSem = 0; 

    while(1){
        // sem_wait(&semClient);

        // sleep(1);
        sem_wait(&semClient);
        // sleep(1);

        if(emptyStack(headNode) != 1){
            printf("thread %d retrived -> [%d] <\n", pthread_self() , headNode->tail->key); 
            pop(headNode);
            // sem_wait(&semClient);
        }
        else{
            printf("I am here");
            sem_post(&semSealer);
            sem_wait(&semClient);

            // sem_wait(&semClient);
            // return;
        }
        sem_getvalue(&semClient, &auxSem);

        printf("[-- sem_value %d\n]", auxSem);
        sem_post(&semClient);
        // 
        // sleep(1);
        
        // sem_wait(&semClient);
        // sem_wait(&semClient);
        // sem_post(&semClient);
    }
}

void* sealer(void *headStack){

    HeadStack *headNode = (HeadStack*) headStack;
    // sem_post(&semClient);
    
    while(1){

        // sem_wait(&semSealer);
        // sem_wait(&semSealer); //0
        
        // sem_post(&semClient);
        // sleep(1);
        // sem_wait(&semSealer);

        push(headNode, generateRandon());
        printf("> %d \n", headNode->head->key);
        tickets++;
        if(tickets%5 == 0){
            sem_post(&semClient);   
            sem_wait(&semSealer);
            // sleep(10);
            // return;
        }
        // sleep(1);
        // sleep(1);

        // showStack(headNode->tail->key);
        // sem_wait(&semSealer);

        // sem_post(&semClient);


        // if(emptyStack(headStack)){
        // }
        // sem_post(&semSealer);
        // sleep(1);
    }
    // showStack(headStack); 
    // printf("-> thread: %d <-\n", headNode->head->key); 
    return NULL; 
}