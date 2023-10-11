#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

int iterations = 0;

typedef struct threadParams
{
    int l;
    int r;
    int *n;
    int *result;
} threadParams;

int calcDivisors(int num)
{
    int i = 11;
    int numberOfEl = 0;

    int numSqrt = floor(sqrt(num));
    while (i < numSqrt)
    {
        if (num % i == 0){
            
            for(int g = num ; g < numSqrt; g+=num ){
                numberOfEl++;    
            }
            numberOfEl++;
            if (numberOfEl > 10){
                return 1;
            }
        }
        i++;
    }
    return 0;
}

void *printDivisors(void *data)
{
    // return NULL;

    threadParams *myData = ((threadParams *)data);
    // myData->n[50];
    // return 0;
    for (int ni = myData->l; ni < myData->r; ni++)
    {
        int number = myData->n[ni];
        // printf("%d\n", number);
        // continue;
        int i = 508079;
        i = (number > 508079) ? number + 1 : 508079;
        if (i % 2 == 0)
            i += 1;
                   
        for (; i < 1000000000; i += 2)
        {
            if (!(i % 3 != 0 && i % 5 != 0 && i % 7 != 0))
                continue;
            if (calcDivisors(i))
            {
                myData->result[ni] = i;
                break;
            }
        }
    }
    return 0;
}


int main(){
    
    int myInput = 0;
    int inputSize = 0;
    scanf("%d", &inputSize);
    int splits = 3;
    threadParams *tp = (threadParams *)malloc(splits*sizeof(threadParams));
    
    int *list = (int *)malloc(inputSize*sizeof(int));
    int *result = (int *)malloc(inputSize*sizeof(int));
    
    int arrayfrag = inputSize/splits;
    int extraLast = (inputSize % splits == 0) ? 0 : 1; 
    pthread_t t1, t2;

    
    for(int i = 0 ; i < inputSize ; i++){
        scanf("%d", &list[i]);
    }
    
    for(int i = 0 ; i < splits ; i++){
        tp[i].l = i*arrayfrag;
        tp[i].r = (i+1)*arrayfrag+((i == splits-1) ? extraLast : 0);
        tp[i].n = list;
        tp[i].result = result;
    }

    
    // for(int i = 0 ; i < splits ; i++){
    //     printf("%d %d\n", tp[i].l , tp[i].r);
    // }

    pthread_create(&t1, NULL, printDivisors, (void*) &tp[0]);
    pthread_create(&t2, NULL, printDivisors, (void*) &tp[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printDivisors(&tp[2]);

    for(int i = 0 ; i < inputSize ; i++){
        printf("%d\n", result[i]);
    }

    return 0;
}

// int main()
// {
//     // sem_init(&semA, 0, 1);
//     // sem_init(&semB, 0, 1);
//     // sem_init(&mutex, 1, 0);

//     int myInput = 0;
//     int inputSize = 0;
//     scanf("%d", &inputSize);
//     threadParams *tp = (threadParams *)malloc(3*sizeof(threadParams));
//     int splits = 3;
//     int arrayfrag = inputSize/splits;
//     // int middle = (inputSize)/splits;

//     for (int i = 0; i <3; i++){
//         tp[i].n = (int*) malloc((arrayfrag+1)*sizeof(int));
//         tp[i].result = (int*) malloc((arrayfrag+1)*sizeof(int));
//     }
    
//     pthread_t t1, t2;

//     int extraLast = (inputSize % splits == 0) ? 0 : 1; 

//     for(int k = 0 ; k < splits ; k++){
//         for (int i = 0; i < arrayfrag+((k == splits-1) ? extraLast : 0); i++)
//         {
//             scanf("%d", &tp[k].n[i]);
//         }
//         tp[k].l = k*arrayfrag;
//         tp[k].r = ((k+1)*arrayfrag)+((k == splits-1) ? extraLast : 0);
//     }
    


//     pthread_create(&t1, NULL, printDivisors, (void*)&tp[0]);
//     pthread_join(t1, NULL);
//     pthread_create(&t2, NULL, printDivisors, (void*) &tp[1]);
//     pthread_join(t2, NULL);
//     printDivisors(&tp[2]);
    

//     for(int k = 0 ; k < splits ; k++){
//         for (int i = 0; i < arrayfrag+((k == splits-1) ? extraLast : 0); i++)
//         {   
//             printf("%d\n", tp[k].n[i]);
//         }
//     }
//     return 0;
// }
