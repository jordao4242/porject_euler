#include <stdio.h>
#include <math.h>

int fibonacci(int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(n>2){
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

double fibonacci_generator(int n){
    const double phi = 1.61803398875;
    return (pow(phi, n)/sqrt(5) - pow(1-phi, n)/sqrt(5));
}

/*int main(){
    int n=1;
    int soma = 0;
    int ref = fibonacci(n);
    while(ref<4000000){
        if(ref%2 == 0){
            soma += ref;
        }
        n++;
        ref = fibonacci(n);
    }
    printf("%d\n", soma);
    printf("%f", fibonacci_generator(30));
    return 0;
}*/

int main(){
    int soma = 0;
    int n = 3;
    int ref = (int)fibonacci_generator(n);
    while(ref<4000000){
        soma += (int)ref;
        n += 3;
        ref = (int)fibonacci_generator(n);
    }
    printf("%d\n", soma);
    return 0;
}