#include <stdio.h>

int is_palindrome(int n){

    int reverse = 0;
    int num = n;
    while(num>0){
        reverse = 10*reverse + num%10;
        num = num/10;
    }
    if(reverse == n){
        return 1;
    }
    return 0;
}

int main(void){
    int largest = 0;
    for(int p=999;p>100;p--){
        for(int q=999;q>100;q--){
            int prod = p*q;
            if(is_palindrome(prod) == 1){
                if(prod>largest){
                    largest = prod;
                }
            }
        }
    }
    printf("%d\n", largest);
    return 0;
}