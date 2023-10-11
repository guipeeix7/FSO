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

int calcDivisors(int num, int numSqrt, int jumper)
{
    if ((num % 2 != 0 && num % 3 != 0 && num % 5 != 0 && num % 7 != 0))
    {
        int counter = 0;
        for (int i = 11; i < numSqrt; i++)
        {
            if (num % i == 0)
            {
                counter++;
                
            }
            if (counter > 9)
            {
                return num;
            }
        }
    }
    return calcDivisors(num + jumper, numSqrt, jumper);
}

void *printDivisors(void *data)
{
    threadParams *myData = ((threadParams *)data);
    int number = myData->n;

    if (number <= 508079 )
    {
        myData->result = 508079;
        return 0;
    }
    int numSqrt = (int)sqrt(number);

    int jumper = (number % 2 == 0) ? 1 : 2;  

    myData->result = calcDivisors(number, numSqrt, jumper);
    // pthread_exit(NULL);
}

int main()
{

    int myInput = 0;
    int inputSize = 0;
    scanf("%d", &inputSize);
    threadParams *tp = (threadParams *)malloc(3 * sizeof(threadParams));
    pthread_t t1, t2;

    while(inputSize--)
    {
        // if(inputSize > 3){
            int num1 = 0, num2 = 0;
            int validInput = 1;
            int validInput2 = 1;
            if (scanf("%d", &tp[0].n) == EOF)
                break;
            // tp[0].n = num1;

            if (scanf("%d", &tp[1].n) == EOF)
                validInput = 0;


            if (scanf("%d", &tp[2].n) == EOF)
                validInput2 = 0;

            pthread_create(&t1, NULL, printDivisors, (void *)&tp[0]);
            if (tp[1].n)
                pthread_create(&t2, NULL, printDivisors, (void *)&tp[1]);
            
            if(validInput2 == 1)
                printDivisors(&tp[2]);

            pthread_join(t1, NULL);
            if (tp[1].n)
                pthread_join(t2, NULL);

            printf("%d\n", tp[0].result);
            if (tp[1].n)
                printf("%d\n", tp[1].result);

            if (tp[2].n)
                printf("%d\n", tp[2].result);
        }
    // }
    return 0;
}
