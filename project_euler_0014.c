#include <stdio.h>

long int collatz(long int n){
    if(n==1){
        return 1;
    }
    if(n%2 == 0){
        return n/2;
    }
    return 3*n+1;
}

int main(void){

    long int biggest = 0;
    long int steps[1000000];
    for(int i = 0;i<1000000;i++){
        steps[i] = 0;
    }
    long int ans;
    for(int i=2;i<1000000;i++){
        long    int num = i;
        long int count = 0;
           
        while(collatz(num)!=1){
            num = collatz(num);
            if(num<i){
                count += steps[num];
                break;
            }
            else{
                count++;
            }
            
        }
        steps[i] = count;
        if(count>biggest){
            biggest = count;
            ans = i;
        }
    }
    printf("%ld\n", ans);

    

    return 0;
}