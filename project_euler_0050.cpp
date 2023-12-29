#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
bool is_prime(long int n){
    if(n<2){
        return false;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    long int N = 1000000;
    vector<long int> primes {};
    for(int i=0;i<N;i++){
        primes.push_back(i);
        //cout << primes[i] << " ";
    }
    int i, j;
    i = 2;
    while(i<=sqrt(N)){
        if(primes[i] != 0){
            for(j=2*i;j<N;j+=i){
                primes[j] = 0;
            }
        }
        i++;
    }

    primes[0] = 0;
    primes[1] = 0;

    primes.erase(std::remove(primes.begin(), primes.end(), 0), primes.end());
    long int count = 0;
    long int num;
    for(int i=0;i<primes.size();i++){
        long int soma = primes[i];
        for(int j=i+1;j<primes.size();j++){
            soma += primes[j];
            if(soma>1000000){
                break;
            }
            if(is_prime(soma)){
                if(j+1-i>count){
                    count = j+1-i;
                    num = soma;
                }
            }
        }
    }

    cout << num << "\n ";
    return 0;
}