#include <stdio.h>       /* standard I/O routines                 */
#include <pthread.h>  
typedef struct {
    int *ar;
    long n;
} subarray;


void *
incer(void *arg)
{
    long i;


    for (i = 0; i < ((subarray *)arg)->n; i++){
        ((subarray *)arg)->ar[i]++;
        if(!(i % 20000))
        printf("(%d  -> %d : %d)\n",pthread_self(),  i , ((subarray *)arg)->ar[i]);
    }
}


int main(void)
{
    int        ar[1000000];
    pthread_t  th1, th2;
    subarray   sb1, sb2;


    sb1.ar = &ar[0];
    sb1.n  = 500000;
    (void) pthread_create(&th1, NULL, incer, &sb1);


    sb2.ar = &ar[0];
    sb2.n  = 500000;
    (void) pthread_create(&th2, NULL, incer, &sb2);
    
    
        (void) pthread_join(th1, NULL);

    (void) pthread_join(th2, NULL);


    return 0;
}