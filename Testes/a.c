#include <stdio.h>       /* standard I/O routines                 */
#include <pthread.h>     /* pthread functions and data structures */

void* PrintHello(void* data)
{
    int tid = (int)data;    /* data received by thread */

    // pthread_join(tid, NULL);            /* wait for thread tid     */
    printf("Hello from new thread %u - got loop at: %d\n", pthread_self(), tid);
    pthread_exit(NULL);	                /* terminate the thread    */
}

/* like any C program, program's execution begins in main */
int main(int argc, char* argv[])
{
    int        rc;         	       /* return value                  */
    pthread_t  thread_id;     	       /* thread's ID (just an integer) */
    int        tid;

    tid = pthread_self();

    int loop = 0; 
    scanf("%d", &loop); 
    for(int i = 0 ; i < loop ; i++){
        rc = pthread_create(&thread_id, NULL, PrintHello, (void*)i);  
    }

    if(rc)                             /* could not create thread */
    {
        printf("\n ERROR: return code from pthread_create is %d \n", rc);
        exit(1);
    }
    sleep(1);
    printf("\n Created new thread (%u) ... \n", thread_id);
}