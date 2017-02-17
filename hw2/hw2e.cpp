#include <iostream>
using std::cout;

double fact(int n){
    double fact = 1;
    if(n == 0)
        return 1;
    else
        for(int i = 1; i <= n; i++){
            fact = fact*i;
        }
    return fact;
} 

double fact2(int n){
    double fact = 1;
    if(n == 0)
        return 1;
    else if( n >= 1)
        fact = n*fact2(n-1);
}

int fibo(int n){
    int fibo = 1;
    int fibo_prev = 1;
    int fibo_old = 1;
    n++;
    for(int i = 1; i <= n-3; i++){
        fibo_old = fibo;
        fibo = fibo + fibo_prev;
        fibo_prev = fibo_old;
    }
    return fibo;
}

int fibo2(int n){
    int fibo = 1;
    if(n == 1 || n == 2)
        return 1;
    else if( n >= 1)
        fibo = fibo2(n-1) + fibo2(n-2);
}

double choose(int n, int r){
    return fact2(n) / (fact2(r)*fact2(n-r));
}

int main(){
  cout << fact(5) << ' ' << fact2(5) << '\n';
  cout << fact(15) << ' ' << fact2(15) << '\n';
  cout << fibo(5) << ' ' << fibo2(5) << '\n';
  cout << fibo(13) << ' ' << fibo2(13) << '\n';
  cout << choose(52,6) << '\n';
}