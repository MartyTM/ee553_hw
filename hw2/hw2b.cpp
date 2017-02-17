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

int main(){
unsigned long long number = 0;
    cout << "Enter a positive integer\n";
    cin >> number;
    if(isPrime(number))
        cout << number << " is Prime\n";
    else
        cout << number << " is Not Prime\n";
}