#include <stdio.h>

int main(void){

    int soma1 = 0;
    int soma2 = 0;

    for(int i=0;i<=100;i++){
        soma1 += i;
        soma2 += i*i;
    }

    int diff = soma1*soma1 - soma2;
    printf("%d\n", diff);

    return 0;
}