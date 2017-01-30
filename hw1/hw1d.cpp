#include <iostream>
using namespace std;

float sum1_f = 0, sum2_f = 0;
double sum1_d = 0, sum2_d = 0; 

int main(){
	
	for(int i = 1; i < 101; i++){
		float f = i;
		sum1_f = sum1_f + (1/f);
	}
	for(int i = 100; i > 0; i--){
		float f = i;
		sum2_f = sum2_f + (1/f);
	}
	
	for(int i = 1; i < 101; i++){
		double d = i;
		sum1_d = sum1_d + (1/d);
	}
	for(int i = 100; i > 0; i--){
		double d = i;
		sum2_d = sum2_d + (1/d);
	}
	
	
	cout << "SUM 1 (FLOAT): " << sum1_f << "\n";
	cout << "SUM 2 (FLOAT): " << sum2_f << "\n";
	cout << "SUM 1 - SUM 2 (FLOAT): " << sum1_f - sum2_f << "\n";
	cout << "SUM 1 (DOUBLE): " << sum1_d << "\n";
	cout << "SUM 2 (DOUBLE): " << sum2_d << "\n";
	cout << "SUM 1 - SUM 2 (DOUBLE): " << sum1_d - sum2_d << "\n";
}