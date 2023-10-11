#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>  



typedef struct DLL{
    int value;    
    struct DLL *prevNodeAddress; 
    struct DLL *proxNodeAddress; 

} DLL; 

typedef struct seedVector{
    int begin; 
    int middle; 
    int end; 
    int find;  
    DLL *v; 
}seedVector;



DLL *init(){
    DLL *headNode = (DLL*) malloc(sizeof(DLL));  
    headNode->proxNodeAddress = NULL; 
    headNode->prevNodeAddress = NULL; 
    return headNode; 
}

void showList(DLL *headNode){
    DLL *temp = headNode->prevNodeAddress; 
    
    while(temp != NULL){
        printf("%d\n",  temp->value);
        temp = temp->proxNodeAddress; 
    }
    return; 
}

int isEmpty(DLL *headNode){
    if(headNode->proxNodeAddress == NULL && headNode->prevNodeAddress == NULL){
        // printf("Double Linked list is empty!\n");
        return 1; 
    } 
    return 0;
}

void orderedInserction(int value, DLL *headNode){
    DLL *newNode = (DLL *) malloc(sizeof(DLL)); 
    newNode->value = value; 
    newNode->proxNodeAddress = NULL; 
    newNode->prevNodeAddress = NULL; 

    DLL *i = headNode->prevNodeAddress; 
    if(isEmpty(headNode)){
        headNode->prevNodeAddress = newNode; 
        headNode->proxNodeAddress = newNode;
        return;  
    }

    //If is first 
    if(value <= headNode->prevNodeAddress->value){
        newNode->proxNodeAddress = headNode->prevNodeAddress; 
        headNode->prevNodeAddress->prevNodeAddress = newNode;
        headNode->prevNodeAddress = newNode;

        return;
    }
    

    //While is not the last ou is lower than the next number
    while(i->proxNodeAddress != NULL && value >= i->proxNodeAddress->value)
        i = i->proxNodeAddress;
    
    //Set the links in new node
    newNode->proxNodeAddress = i->proxNodeAddress; 
    newNode->prevNodeAddress = i; 

    // set the links to the new node 
    if(i->proxNodeAddress == NULL){
        headNode->proxNodeAddress = newNode; 
    }
    else{
        i->proxNodeAddress->prevNodeAddress = newNode;
    }
    i->proxNodeAddress = newNode; 

    return; 
}

void *verifyRand(void *data){
    seedVector *myData = ((seedVector*) data) ;
    
    int seed = 0; 
    for (int i = myData->begin; i <= myData->end; i++){
        seed = i;
        for(int k = 1; k < 100000; k++){

            rand_r(&seed);
        }
        if((rand_r(&seed) % 8 == myData->find)){
            orderedInserction(i, myData->v);
        }
        // printf("%d ok\n", i);
    }
    // showList(myData->v);
    // printf(")%d(\n", myData->v);

}

int main(){
    DLL *headNode = init();

    seedVector *sdVa = (seedVector*) malloc(sizeof(seedVector)); 
    seedVector *sdVb = (seedVector*) malloc(sizeof(seedVector)); 
    int ll, lh, search; 

    scanf("%d %d %d", &ll, &lh, &search);

    int middle = (ll+lh)/2;
    pthread_t t1, t2; 

    sdVa->v = headNode;
    sdVa->begin = ll; 
    sdVa->end = middle; 
    sdVa->find = search; 

    pthread_create(&t1, NULL, &verifyRand, (void*) sdVa);
    // printf("(%d)\n", headNode);


    if((lh - ll) > 1){
        sdVb->v = headNode;
        sdVb->begin = middle+1; 
        sdVb->end = lh; 
        sdVb->find = search; 
        pthread_create(&t2, NULL, &verifyRand, (void*) sdVb);
        // 
    }
    // printf("GLUGLUGLUU\n" );
    
    (void) pthread_join(t1, NULL);
    (void) pthread_join(t2, NULL);
    // printf("(%d)\n", headNode);
    showList(sdVb->v);

    pthread_exit(NULL);
    pthread_exit(NULL);
}