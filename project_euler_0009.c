#include <stdio.h>


int main(void){

    int a,b,c;
    for(a=1;a<1000;a++){
        for(b=a+1;b<1000;b++){
            for(c=b+1;c<a+b;c++){
                if(a*a+b*b == c*c && a+b+c == 1000){
                    long int prod = a*b*c;
                    printf("%d %d %d %ld\n", a,b,c,prod);
                }
            }
        }
    }
    return 0;
}