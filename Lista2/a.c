#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>  

typedef struct Vector{
    int size; 
    int *v; 
}Vector; 


int comparator(const void *p, const void *q) 
{
    // int* l = ((int *)p);
    // int* r = ((int *)q); 
    // return (l - r);
    return ( *(int*)p - *(int*)q );

}

void *ordena(void *data){
    Vector *vector = ( (Vector*) data);
    // printf("%d\n", vector->v[3]); 
    qsort(vector->v, vector->size, sizeof(int), comparator);
    
    // for(int i = 0 ; i < vector->size ; i++){
    //     printf(" %d", vector->v[i]); 
    // }
    // printf("\n");
    // qsort((void*)arr, size, sizeof(arr[0]), comparator);
}

void checkElements(Vector *Va, Vector *Vb){ 
    for(int i = 0 ; i < Va->size ; i++){
        if(Va->v[i] != Vb->v[i]){
            printf("Diferentes\n");
            return; 
        }
    }
    printf("Mesmos elementos\n");
    return;
}

int main(){
    int vectorSize = 0;
    // int *va, *vb; 
    Vector *Va,*Vb; 
    Va = (Vector*) malloc(sizeof(Vector)); 
    Vb = (Vector*) malloc(sizeof(Vector)); 

    // vectorSize = 0; 
    scanf("%d", &vectorSize); 

    Va->size = vectorSize; 
    Vb->size = vectorSize; 


    Va->v = (int*) malloc(vectorSize*sizeof(int)); 
    Vb->v = (int*) malloc(vectorSize*sizeof(int));

    for(int i = 0 ; i < vectorSize ; i++){
        scanf(" %d", &Va->v[i]); 
    }
    
    for(int i = 0 ; i < vectorSize ; i++){
        scanf(" %d", &Vb->v[i]); 
    }
    
    pthread_t tid1, tid2;
    // printf("%d %d\n" , &Va[0] , (void*) Va); 
    pthread_create(&tid1, NULL, &ordena, (void*) Va);
    pthread_create(&tid2, NULL, &ordena, (void*) Vb);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    checkElements(Va,Vb);


    pthread_exit(NULL);
    pthread_exit(NULL);
}