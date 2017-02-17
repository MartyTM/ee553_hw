#include <iostream>
#include <string>
using namespace std;


// Changing the getName() and getMemberCount() member functions to be constant (readonly)
// fixes the error caused by the consts added in the main function

class Person {
private:
	string name;
	int age;
	static int count;// in this context, static means class shared
public:
	Person(string n, int a):name(n), age(a) {
		count++;
	}

	~Person() {
		count--;
	}

	string getName() const {
		return name;
	}
	
	int getMemberCount() const {
		return count;
	}
	static int getCount() {
		return count;
	}

	friend ostream&  operator <<(ostream& s, const Person& p) {
        return s << p.name << " " << p.age;
	}
};

int Person::count = 0;

void f() {
	Person p3("Maria", 32);
}

// Changing the parameter to "const Person& p" from "Person p" fixes the counter
// This has something to do with the destructor being called every time the function
// finishes, the destructor was being called since the local copy dies

// I just changed it to a const reference, but I saw there is something called a
// Copy Constructor that's probably better for this, but I didnt't fully understand
// the concept 
void g(const Person& p) {
	cout << p << '\n';
}

int main() {
	cout << Person::getCount();
	f();
	const Person p1("Dov", 50);
	cout << p1.getName() << '\n';
	
	const Person p2("Yu-Dong", 45);
    //
	for (int i = 0; i < 5; i++)
		g(p2);
	cout << p1 << '\n';
	cout << p2.getMemberCount();
}