#include <stdio.h>
#include <stdlib.h>

geraTeste(int semente){
    // int semente = 1;
    for (int i = 5; i < 20; i++){
        for (int j = 1; j < 10000; j++)
            rand_r(&semente);
        printf("%d\n", rand_r(&semente) % 256);
    }
}

int main(){
    int semente;
    printf("Digite a sua semente:\n");
    scanf("%d", &semente);
    // for (int i = 0; i < 20; i++){
    geraTeste(semente);
    printf("%d\n", rand_r(&semente) % 256);
    // }
    // geraTeste();
}
