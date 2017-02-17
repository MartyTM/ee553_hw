#include <iostream>
using std::cout;
using std::cin;

bool isPrime(unsigned long long p){
    if(p <= 1)
        return false;
    else
        for(unsigned long long n = 2; n < p; n++){
            if(p % n == 0)
                return false;
        }
    return true;
}

int countPrimes(unsigned long long a, unsigned long long b){
    int count = 0;
    for(unsigned long long i = a; i <= b; i++){
        if(isPrime(i))
            count++;
    }
    return count;
}

int main(){
    unsigned long long num1, num2;
    cout << "Enter two positive integers (smallest first) separated by a space\n";
    cin >> num1 >> num2;
    cout << countPrimes(num1, num2) << "\n";
}