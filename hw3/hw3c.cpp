#include <iostream>
#include <iomanip>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

class vec2d{
private:
    double X,Y;
public:
    vec2d(double x = 0.0, double y = 0.0) : X(x), Y(y) {}

    vec2d add(const vec2d v) const{
        return vec2d(X + v.X, Y + v.Y);
    }

    friend ostream& operator <<(ostream& s, vec2d v) {
        return s << "X = " << v.X << " Y = " << v.Y;
    }

    friend vec2d operator +(vec2d A, vec2d B) {
        return vec2d(A.X + B.X, A.Y + B.Y); 
    }
};

vec2d polarToVec(double theta, double dist){
    return vec2d(dist*sin(theta*M_PI/180.0), dist*cos(theta*M_PI/180.0));
}

int main(){
    vec2d robotLoc(0.0,0.0);
    while(1){
        double theta = 0.0;
        double dist = 0.0;
        cout << "Enter an angle (in degrees) and a distance (separated by a space)\n";
        cin >> theta >> dist;

        if (theta < 0 || dist < 0) {
            break;
        }
        else
            robotLoc = robotLoc + polarToVec(theta, dist);
            // Using fixed and setprecision to round display to 4 decimal places
            // Else cos(pi/2) doesn't return 0 and the results are weird
            cout << fixed << setprecision(4) << "Location: " << robotLoc << "\n";
    }
    cout << "Terminating Program\n";
    return 0;
}