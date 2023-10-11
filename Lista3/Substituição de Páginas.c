#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
// #include <pthread.h>
// #include <unistd.h>
// #include <semaphore.h>

//The stack
typedef struct Stack{
    struct Stack *prox;
    int key;  
}Stack; 

//Node to begin and end of stack
typedef struct HeadStack{
    Stack *head;
    Stack *tail;    
    int stackLimit; 
    int stackSize;
}HeadStack; 

//Init the node that will point to begin and end of my Stack
HeadStack *init(){
    HeadStack *root = (HeadStack*) malloc(sizeof(HeadStack)); 
    root->head = NULL; 
    root->tail = NULL; 
    root->stackSize = 0;
    return root;  
}

//Check if the stack is empty or not
int emptyStack(HeadStack *headStack){
    if(headStack->tail == NULL){
        // printf("Sem tickets parça\n"); 
        return 1; 
    }
    return 0;
}

//Pop from the end of stack
void pop(HeadStack *headStack){
    if(headStack->tail == NULL){
        // printf("Sem tickets parça\n"); 
        // sem_post(&semClient);

        return; 
    }
    
    Stack *nextAux = headStack->tail->prox;
    free(headStack->tail);
    headStack->tail = nextAux; 

    if(headStack->tail == NULL && headStack->head != NULL){
        headStack->head = NULL;
    }
    
    headStack->stackSize -= 1; 
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
    headStack->stackSize +=1;
    return ;  
}

//Display all the stack
void showStack(HeadStack *HeadStack){
    Stack *aux = HeadStack->tail; 
    while(aux != NULL){
        printf("[%d ]", aux->key); 
        aux = aux->prox; 
    }
    printf("\n");
    return; 
}

int search(int value, HeadStack *headNode, char opt[]){
    Stack *temp = headNode->tail;
    // printf("[%d ->  ", headNode->tail->key);
    while(temp != NULL){
        // printf("%d -> ", temp->key);
        if(temp->key == value) {
            // printf(" aaaa]\n");
            return 1;    
        }
        temp = temp->prox;
    }
    // printf("]\n");
    // printf("Value not found!\n"); 
    return 0; 
}

void rebootStack(int newSizeOfFrames, int* frameVector,HeadStack * headStack){
    while(headStack->head != NULL && headStack->tail!=NULL){
        pop(headStack);
    }
    headStack->stackSize =0; 
}

int comparator(const void *p, const void *q) 
{

    return ( *(int*)q - *(int*)p  );

}

typedef struct BeladyDetec{
    int sizeOfFrame;
    int numberOfpageFaults;
}BeladyDetec; 

int main(){
    // stackLimit
    int numberOfprocess = 0; 
    scanf("%d", &numberOfprocess);
    int *frame = (int*) malloc(numberOfprocess * sizeof(int));  
    BeladyDetec *beladyDec = (BeladyDetec*) malloc(numberOfprocess * sizeof(BeladyDetec));

    for(int i = 0 ; i < numberOfprocess ; i++){
        scanf("%d", &frame[i]);
    }   
    int frameSize = 0; 
    HeadStack *headStack = init();  
    int k = 0;
    

    while(scanf("%d", &frameSize) != EOF){
        rebootStack(frameSize,frame,headStack);
        beladyDec[k].sizeOfFrame =  frameSize;
        int pageFaults = 0; 
        headStack->stackLimit = frameSize;
        for(int i = 0 ; i < numberOfprocess ; i++){

            if(search(frame[i], headStack, "") == 0){
                pageFaults++;     
                push(headStack, frame[i]);

                if(headStack->stackLimit == headStack->stackSize){
                    pop(headStack);
                }
            }
        } 
        printf("%d %d\n", frameSize, pageFaults);
        beladyDec[k++].numberOfpageFaults = pageFaults;
    }

    qsort(beladyDec, k, sizeof(BeladyDetec), comparator);

    int lastState = beladyDec[0].numberOfpageFaults;
    for(int i = 0 ; i < k ; i++){
        // printf("\n\n%d %d\n", beladyDec[i].sizeOfFrame, beladyDec[i].numberOfpageFaults);
        if(lastState > beladyDec[i].numberOfpageFaults){
            printf("Belady detectado\n");
            return 0;
        }
        // // printf("%d meme\n", beladyDec[i].sizeOfFrame);
        // lastState = beladyDec[i].numberOfpageFaults; 
    }
    printf("Sem anomalia\n");
    return 0;
    // (pageFaults > 0) ? printf("%d %d\n", frameSize, pageFaults) : printf("Sem anomalia\n");

}