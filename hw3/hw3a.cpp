#include <iostream>
using namespace std;

class Vec3d{
private:
    double X,Y,Z;

public:
    //Constructor 
    Vec3d(double x = 0.0, double y = 0.0, double z = 0.0) : X(x), Y(y), Z(z) {}

    //Add and dot member functions (methods)
    Vec3d add(const Vec3d v) const{
        return Vec3d(X + v.X, Y + v.Y, Z + v.Z);
    }

    double dot(const Vec3d v) const{
        return X*v.X + Y*v.Y + Z*v.Z;
    }

    // Overloads for <<, +, and * operators
    friend ostream& operator <<(ostream& s, Vec3d v) {
        s << "(" << v.X << ", " << v.Y << ", " << v.Z << ")";
        return s;
    }

    friend Vec3d operator +(Vec3d A, Vec3d B) {
        return Vec3d(A.X + B.X, A.Y + B.Y, A.Z + B.Z); 
    }

    friend Vec3d operator *(Vec3d v, double S) {
        return Vec3d(S*v.X, S*v.Y, S*v.Z); 
    }
    friend Vec3d operator *(double S, Vec3d v) {
        return Vec3d(S*v.X, S*v.Y, S*v.Z); 
    }

};

int main() {
	const Vec3d a(1.0, 2, 2.5); //(1.0, 2.0, 2.5) (x,y,z)
	cout << a << '\n';
	Vec3d b(5.0);         //(5.0, 0.0, 0.0)
	Vec3d c = a + b;
	cout << c << '\n';
	Vec3d c2 = a.add(b);   // call a method
	cout << c2 << '\n';
	double d = a.dot(b); //  dot product = a.x*b.x + a.y*b.y + a.z*b.z
	cout << d << '\n';

	Vec3d e = a * 2;   //scalar multiplication
	cout << e << '\n';
	Vec3d f = 2 * a;   //scalar multiplication
	cout << f << '\n';
}