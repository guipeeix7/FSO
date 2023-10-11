#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
int iterations = 0;

typedef struct threadParams
{
    int n;
    int result;
} threadParams;

int calcDivisors(int num)
{
    int i = 11;
    int numberOfEl = 0;

    int numSqrt = (int)(sqrt(num));
    while (i < numSqrt)
    {
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
    threadParams *myData = ((threadParams *)data);
    int number = myData->n;

    if (number <= 508079)
    {
        myData->result = 508079;
        return 0;
    }

    int i = (number > 508079) ? number + 1 : 508079;
    if (i % 2 == 0)
        i += 1;

    for (; i < 100000000; i += 2)
    {
        if (!(i % 3 != 0 && i % 5 != 0 && i % 7 != 0))
            continue;

        if (calcDivisors(i))
        {
            myData->result = i;
            // printf("%d\n", i);
            return 0;
        }
    }
    pthread_exit(NULL);
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
        int num1 = 0,num2 = 0; 
        scanf("%d", &num1);
        tp[0].n = num1;
        pthread_create(&t1, NULL, printDivisors, (void*) &tp[0]);

        if(inputSize-- ){
            scanf("%d", &num2);
            tp[1].n = num2;
            pthread_create(&t2, NULL, printDivisors, (void*) &tp[1]);
        } ;

        pthread_join(t1, NULL);
        if(num2) pthread_join(t2, NULL);
     
        printf("%d\n", tp[0].result);
        if(num2) printf("%d\n", tp[1].result);
        
    }
    printf("--> %d <--\n", iterations);

    // sleep(1);
    return 0;
}
