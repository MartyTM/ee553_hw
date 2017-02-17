#include <iostream>
using namespace std;

int number = 0;
int count = 0;

int main(){
	while(1) {
		cout << "Enter an integer greater than 0\n";
		cin >> number;
		if (number > 0)
			break;
		cout << "Invalid input!!\n";
	}
	cout << "You entered " << number << "\n";
	
	while (number != 1) {
		if (number % 2 == 0)
			number = number / 2;
		else
			number = (3*number)+1;
		cout << number << "  ";
		count++;
	}
	cout << "\nNumber of steps: " << count << "\n";	
}
