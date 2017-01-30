#include <iostream>
using namespace std;

int s1 = 0;
int s2 = 0;

int main(){

for(int i = 1; i<=100; i++){
	s1 = s1 + i;
}

s2 = (100*(100+1))/2;

cout << "Loop Sum = " << s1 << "\n";
cout << "Gauss Sum = " << s2 << "\n";
}