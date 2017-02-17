#include <iostream>
#include <cmath>
using namespace std;

class polar {
private:
    double theta, dist
public:
    polar(double t = 0.0, double d = 0.0) : theta(t), dist(d) {}
    vec2d convToVec(polar p) {

    }
}

class vec2d{
private:
    double X,Y;
public:
    vec2d(double x = 0.0, double y = 0.0) : X(x), Y(y) {}

    vec2d add(const vec2d v) const{
        return Vec3d(X + v.X, Y + v.Y);
    }

    friend ostream& operator <<(ostream& s, vec2d v) {
        return s << "(" << v.X << ", " << v.Y << ")";
    }

    friend vec2d operator +(vec2d A, vec2d B) {
        return Vec2d(A.X + B.X, A.Y + B.Y); 
    }
};