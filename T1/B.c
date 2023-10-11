#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to print the divisors

int comparator(const void *p, const void *q) 
{

    return ( *(int*)p-*(int*)q   );
}

void printDivisors(long int n)
{
    // Note that this loop runs till square root
    long int sqrtV = sqrt(n);
    int primes[122] = {0};
    int numberOfEl = 0; 
    int i = 10; 
    for (; numberOfEl < 10; i++)
    // for (; i<=sqrtV; i++)
    {
        if (n%i == 0 && numberOfEl <10)
        {
            // If divisors are equal, print only one
            if (n/i == i){
                numberOfEl++;
                primes[numberOfEl-1] = i;
                printf("%ld ", i);
            }
            else // Otherwise print both
            {
                printf("%ld %ld ", i, n/i);
                numberOfEl++;
                primes[numberOfEl-1] = i;
                numberOfEl++;
                primes[numberOfEl-1] = n/i;
            }
        }

    }
    long int crazy = i;
    printf("[%d]\n", crazy);
    for (int i=1; i<=sqrtV; i++){

    }

    printf("\n%d\n", numberOfEl);

    qsort(primes, numberOfEl, sizeof(int), comparator);
    for(int i = 0 ; i < numberOfEl ; i++){
        printf(" %ld ", primes[i]);
    }
    printf("\n");
}
 
/* Driver program to test above function */
int main()
{
    printf("The divisors of 100 are: \n");
    long int myInput = 0;  
    while(scanf("%d", &myInput) != EOF){
        printDivisors(myInput);
    }
    return 0;
}