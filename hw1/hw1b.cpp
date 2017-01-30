#include <iostream>
#include <math.h>

using namespace std;

float r_init = 2.000;
float pi = atan(1)*4;

float ngons(int n){
	float r = r_init;
	if ( n < 3)
		return 0;
	else if ( n == 3 )
	cout << "Radius is : " << r;
	else{
		for (int i = 4; i <= n; i++){
			r = r / (cos ( (float)(pi / i) ) );
		}
	}
	return r;
}


int main(){
	cout << "Radius for different n\n";
	cout << "n = 1;" << " r = " << ngons(1) << " (Not Valid!!)\n";
	cout << "n = 10;" << " r = " << ngons(10) << "\n";
	cout << "n = 100;" << " r = " << ngons(100) << "\n";
	cout << "n = 1000;" << " r = " << ngons(1000) << "\n";
	cout << "n = 10000;" << " r = " << ngons(10000) << "\n";
	cout << "n = 100000;" << " r = " << ngons(100000) << "\n";
	cout << "n = 1000000;" << " r = " << ngons(1000000) << "\n";
}