#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <pthread.h>
#include<sys/wait.h>
int iterations = 0;

typedef struct threadParams
{
    int n;
    // int result
} threadParams;

int calcDivisors(int num)
{
    int i = 11;
    int numberOfEl = 0;

    int numSqrt = (int)sqrt(num);
    while (i < numSqrt)
    {   
        // iterations++;
        if (num % i == 0)
        {
            numberOfEl++;
            if (numberOfEl > 10)
            {
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
    threadParams *myData = ((threadParams*) data) ;
        // return 0;
    int number = myData->n;

    // printf("[%d] \n", number);
    // int maxNum = 100000000;
    int i = 508079;
    i = (number > 508079) ? number + 1 : 508079;
    if(i%2 == 0) i+=1;

    for (; i < 100000000; i+=2)
    {
        if(!(i % 3 != 0 && i % 5 != 0 && i % 7 != 0)) continue;
        if (calcDivisors(i))
        {
            printf("%d\n", i);
            return 0;
        }
    }
}

int main()
{

    int myInput = 0;
    int inputSize = 0;
    scanf("%d", &inputSize);
    threadParams *tp =  (threadParams*) malloc(2*sizeof(threadParams)); 

    pthread_t t1,t2; 

    

    while (inputSize--)
    {
        // if(leia(n)== EOF) break;
       
        scanf("%d", &myInput);
        tp[2].n = myInput;
        printDivisors( &tp[2]);

        if(!inputSize--) break;
        scanf("%d", &myInput);
        tp[0].n = myInput;
        pthread_create(&t1, NULL, printDivisors, (void*) &tp[0]);
        pthread_join(t1, NULL);

        if(!inputSize-- ) break;
        scanf("%d", &myInput);
        tp[1].n = myInput;
        pthread_create(&t2, NULL, printDivisors, (void*) &tp[1]);
        pthread_join(t2, NULL);
        
    }
        printf("--> %d <--\n", iterations);

    // sleep(1);
    return 0;
}
