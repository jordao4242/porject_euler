#include <stdio.h>
#include <math.h>

long int triangular_number(long int n){
    return (n*n+n)/2;
}

int count_divisors(long int n){
    int count = 0;
    double root = sqrt(n);
    for(int i=1;i<=root;i++){
        if(n%i == 0){
            if(i == root){
                count++;
            }
            else{
                count += 2;
            }
        }
    }
    return count;
}
int main(void){

    int num_div = 0;
    long int n = 1;
    long int triangular;
    while(num_div<500){
        triangular = triangular_number(n);
        num_div = count_divisors(triangular);
        n++;
    }
    printf("%ld\n", triangular);
    

    return 0;
}