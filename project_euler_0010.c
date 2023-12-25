#include <stdio.h>
#include <math.h>


int main(void){
    int N = 2000000;
    int es[N];
    for(int i=0;i<N;i++){
        es[i] = i;
    }

    int i = 2;
    es[0] = 0;
    es[1] = 0;
    int root = (int)sqrt(N);
    while(i<root){
        for(int j=2*i;j<N;j+=i){    
            es[j] = 0;
        }
        i++;
    }
    long int soma = 0;
    for(int i=0;i<N;i++){
        if(es[i] != 0){
            //printf("%d  ", es[i]);
            soma += es[i];
        }
    }
    printf("%ld\n", soma);
    return 0;
}