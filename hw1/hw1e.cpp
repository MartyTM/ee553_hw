#include <iostream>
using namespace std;

int n = 0;
float prod = 1;

int main(){
	while(1) {
		cout << "Enter an integer\n";
		cin >> n;
		if (n >= 0)
			break;
		cout << "Invalid input!!\n";
	}
	
	for(int i = n; i > 0; i--){
		prod = prod * i;
	}
	
	cout << n << "! is: " << prod << "\n";
}