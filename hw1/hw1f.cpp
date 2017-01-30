#include <iostream>
#include <cmath>
using namespace std;

int n = 0;
float s1 = 0, s2 = 0;

int main(){
	n = 100000;
	
	for ( int i = 1; i <= n; i++ ){
		float k = i;
		s1 = s1 + 1 / (k*k);
	}
	for ( int i = n; i > 0; i-- ){
		float k = i;
		s2 = s2 + 1 / (k*k);
	}

	cout << "S1: " << sqrt(6 * s1) << "\n";
	cout << "S2: " << sqrt(6 * s2) << "\n";	
}