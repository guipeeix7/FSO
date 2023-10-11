#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include<sys/wait.h>

// int main(){
//     printf("%d", gettimeofday());
// }

int main(int argc, char *argv[ ]){
    char *temp,*temp1,*temp2;
    // temp=;  //filename
    // temp1=; 
    temp2="world";
    for(int i = 0 ; i < argc ; i++){
        fork()
        int k = execl("/bin/sleep", "1.5\0");


    }
    // wait(NULL);

    printf("r = [%d]\n", k);
    printf ("Erro: %s\n",strerror(errno));


}

// int main(int argc, char *argv[ ])
// {
//     struct timeval current_time;
//     gettimeofday(&current_time, NULL);


//     printf("\n%d\n", argc); 
//     int k = 0; 
    
//     execl("apt-get" , "moo");
//     // k = execl("/bin/sh","-c" ,"/bin/eunaoexisto 123");
//     // if (k == -1)
//     printf ("Erro: %s\n",strerror(errno));
//     printf("\n%d\n", k);

//     struct timeval current_timeEnd;
//     gettimeofday(&current_timeEnd, NULL);
    
    
//     // int execl(const char *pathname, const char *arg, /*, (char *) NULL */);
    
//     printf("Return: %d , Total: %d.%d sec, ",k,  (current_timeEnd.tv_sec-current_time.tv_sec),(current_timeEnd.tv_usec-current_time.tv_usec) );
//     return 0;
// }