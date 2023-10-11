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

void *printDivisors(void *data)
{
    threadParams *myData = ((threadParams *)data);

    for (int ni = myData->l; ni < myData->r; ni++)
    {
        int number = myData->n[ni];
        if (number <= 508079)
        {
            myData->result[ni] = 508079;
            continue;
        }
        int i = (number > 508079) ? number + 1 : 508079;
        if (i % 2 == 0)
            i += 1;

        for (; i < 100000000; i += 2)
        {
            if (!(i % 3 != 0 && i % 5 != 0 && i % 7 != 0))
                continue;
            int k = 11;
            int numberOfEl = 0;

            // int num = (int)sqrt(num);
            double numSqrt = (int)sqrt(i);

            while (k < numSqrt)
            {
                // iterations++;
                if (i % k == 0)
                {
                    numberOfEl++;
                    if (numberOfEl > 10)
                    {
                        myData->result[ni] = i;
                        i = 100000000;
                        break;
                    }
                }
                k++;
            }
        }
    }
    // pthread_exit(NULL);

    // printf("THREAD RUNNING\n");
}

int main()
{

    int myInput = 0;
    int inputSize = 0;
    scanf("%d", &inputSize);
    int splits = 3;
    threadParams *tp = (threadParams *)malloc(splits * sizeof(threadParams));

    int arrayfrag = inputSize / splits;
    int extraLast = 0;
    if (inputSize % splits == 1)
    {
        extraLast = 1;
    }
    else if (inputSize % splits == 2)
    {
        extraLast = 2;
    }
    pthread_t t1, t2;

    for (int i = 0; i < splits; i++)
    {
        tp[i].l = 0;
        tp[i].r = arrayfrag + ((i == splits - 1) ? extraLast : 0);
        tp[i].n = (int *)malloc((inputSize + 1) * sizeof(int));
        tp[i].result = (int *)malloc((inputSize + 1) * sizeof(int));
        
    }

    for (int i = 0; i < arrayfrag; i++)
    {
        scanf("%d", &tp[0].n[i]);
    }
    for (int i = 0; i < arrayfrag; i++)
    {
        scanf("%d", &tp[1].n[i]);
    }
    for (int i = 0; i < (arrayfrag + 1); i++)
    {
        scanf("%d", &tp[2].n[i]);
    }

    pthread_create(&t1, NULL, printDivisors, (void *)&tp[0]);
    pthread_create(&t2, NULL, printDivisors, (void *)&tp[1]);
    printDivisors(&tp[2]);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    for (int i = 0; i < arrayfrag; i++)
    {
        printf("%d\n", tp[0].result[i]);
    }
    for (int i = 0; i < arrayfrag; i++)
    {
        printf("%d\n", tp[1].result[i]);
    }
    for (int i = 0; i < (arrayfrag + extraLast); i++)
    {
        printf("%d\n", tp[2].result[i]);
    }
    // printf("->> %d <<-\n", iterations);

    return 0;
}
