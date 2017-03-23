// Author: Martin Marshalek
// Cite: Kyle Emanuele
#include <iostream>
#include <cmath>
using namespace std;

class JulianDate {
private:
    double jday;

public:
    JulianDate(int yr=2000,int mn=1, int day=1, int hr=0,int min=0, int sec=0) {

        double K = day + - 0.5 + hr/24.0 + min/(24.0*60.0) + 
                   sec/(24.0*60.0*60.0);
        jday = K-32075+1461*(yr+4800+(mn-14)/12)/4+367*
               (mn-2-(mn-14)/12*12)/12-3*((yr+4900+(mn-14)/12)/100)/4;
        jday -= 2451544.5;
    }
    JulianDate (double days) : jday(days){}

    void convJD(int& yr, int& mn, int& day, int& hr, int& min, int& sec) const{
        double jdtemp = jday;
        jdtemp += 2451544;
        int JDint = jdtemp;

        double ut = jdtemp - JDint;
        jdtemp += 1;
        int L = jdtemp+68569;
        int N = 4*L/146097;
        L= L-(146097*N+3)/4;
        int I= 4000*(L+1)/1461001;
        L= L-1461*I/4+31;
        int J= 80*L/2447;
        int K= L-2447*J/80;
        L = J/11;
        J = J+2-12*L;
        I = 100*(N-49)+I+L;
        yr = I;
        mn = J;
        day = K;

        int ut_modi = round(ut*24*60*60);
        hr = ut_modi/3600;
        min = (ut_modi%3600)/60;
        sec = (ut_modi%3600)%60;
    }

    int getyr() const{
        int yr, mn, day, hr, min, sec;
        convJD(yr, mn, day, hr, min, sec);
        return yr;
    }

    int getmn() const{
        int yr, mn, day, hr, min, sec;
        convJD(yr, mn, day, hr, min, sec);
        return mn;
    }

    int getDay() const{
        int yr, mn, day, hr, min, sec;
        convJD(yr, mn, day, hr, min, sec);
        return day;
    }

    int gethr() const{
        int yr, mn, day, hr, min, sec;
        convJD(yr, mn, day, hr, min, sec);
        return hr;
    }

    int getMin() const{
        int yr, mn, day, hr, min, sec;
        convJD(yr, mn, day, hr, min, sec);
        return min;
    }

    int getSec() const{
        int yr, mn, day, hr, min, sec;
        convJD(yr, mn, day, hr, min, sec);
        return sec;
    }
    
    friend double operator-(JulianDate a, JulianDate n){
        double diff = a.jday-n.jday;
        return diff;
    }

    friend ostream& operator <<(ostream& s, JulianDate j){
        int yr,mn,day,hr,min,sec;
        j.convJD(yr,mn,day,hr,min,sec);
        s << yr << ' ' << mn << ' ' << day << ' ' << 
        hr << ' ' << min << ' ' << sec;
        return s;
    }

    friend JulianDate operator+(JulianDate a, double b){
        double jday_temp = a.jday + b;
        return JulianDate(jday_temp);
    }

};

int main() {
    const JulianDate d1(2017, 2, 13, 20, 00, 00);
    const JulianDate d1b(2017, 2, 13, 22, 00, 00);
    cout << d1b - d1 << '\n'; // 2 hrs = 2/24 day

    const JulianDate tomorrow = d1 + 1;
    cout << tomorrow; // 2017 2 14 20 00 00
    cout << tomorrow - d1 << '\n';
    // hh:mm:ss  20/24  20/24.0
    const JulianDate d2(2017, 2, 19); // 00:00:00
    const JulianDate d3 = d2 + 3; // what is it 3 days later?
    double days   = d3 - d1;

    int yr = d3.getyr();
    int mn = d3.getmn();
    int day = d3.getDay();
    int hr = d3.gethr();
    int min = d3.getMin();
    int sec = d3.getSec();
    cout << d1 << '\n';
    cout << d2 << '\n';
    cout << d3 << '\n';
    cout << yr << " " << mn << " " << day <<" "<<
        hr << " " << min << " " << sec << '\n';
    // Not every operation makes sense!
    //	JulianDate d5 = d3 * d1;
    JulianDate torture(2017, 2, 27); // 00:00:00
    for (int i = 0; i < 3; i++) {
        cout << torture.getyr() << " " << torture.getmn() << " " << torture.getDay() << '\n';
        torture = torture + 1;
    }
}