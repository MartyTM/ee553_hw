#include <iostream>
#include <math.h>
#include <iomanip>

using std::cout;
using std::setw;


int windChill(int temp, int speed){
    int chill = 0;
    chill = round(35.74+0.6215*temp-35.75*pow(speed, 0.16)+0.4275*temp*pow(speed, 0.16));
    return chill;
}

int main(){
    cout << "Windchill in F, using NOAA Windchill data\n\n";
    for( int v = 5; v <= 60; v += 5){
        if( v == 5 ) {
            cout << setw(2) << " " << "  ";
            for(int t = 40; t >= -45; t -= 5)
                cout << setw(4) << t << " ";
            cout << "<-- TEMP(F) \n\n";
        }
        cout << setw(2) << v << "  ";
        for(int t = 40; t >= -45; t -= 5){
            cout << setw(4) << windChill(t,v) << " ";
        }
        cout << "\n";
    }
    cout << setw(2) << "/\\" << "\n" << "||\n||\n" << "WIND SPEED(mph)\n";
}