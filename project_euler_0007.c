#include <stdio.h>
#include <math.h>

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

int main(void){

    int count = 0;
    int i = 2;
    while(count != 10001){
        if(is_prime(i) == 1){
            count++;
        }
        i++;
    }

    printf("%d\n", i-1);

    return 0;
}