#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int is_prime(long int n){
    if(n<2){
        return 0;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i == 0){
            return 0;
        }
    }

    return 1;
}

int main(){
    long int div;
    long int number = 600851475143;
    long int max_before_sqrt;
    long int max_after_sqrt;
    for(int i=2;i<sqrt(number);i++){
        if(number % i == 0){
            if(is_prime(i) == 1){
                max_before_sqrt = i;
            }
            div = number/i;
            if(is_prime(div) == 1){
                printf("%ld \n", div);
                return 0;
            }
        }
    }
    printf("%ld\n", max_before_sqrt);
    return 0;
    
}