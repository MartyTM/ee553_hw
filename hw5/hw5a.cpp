#include <iostream>
#include <cmath>
using namespace std;

class JulianDate {
private:
	double jday, ut;
    int year, month, day, hour, min, sec;

public:
    JulianDate(int y = 0, int m = 0, int d = 0, int h = 0, int mi = 0, 
    int s = 0): year(y), month(m), day(d), hour(h), min(mi), sec(s) {
		ut = (double)(hour + min/60 + sec/3600);
		jday = (double)(day - 32075 + 1461 * (year + 4800 + (month - 14)/12) 
			   / 4 + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3 * 
			   ((year + 4900 + (month - 14)/12)/100)/4) + ut/24;
	}

	JulianDate convJD(double jd) const{
		int hour, min, sec, day, month, year;
		double ut;
		
		ut = (double)((jd - floor(jd))*24);
		hour = floor(ut);
		min = floor((ut-floor(ut))*60);
		sec = (((ut - floor(ut))-min)*60)*3600;
		double jday_temp = jd - ut/24;
		cout << ut << ' ' << hour << ' ' << min << ' ' << sec << endl;

		double L = jd + 68569;
		double N = 4*L/146097;
		L = L - (146097*N+3)/4;
		double I = 4000 * (L+1) / 1461001;
		L = L - 1461 * I / 4 + 31;
		double J = 80 * L / 2447;
		double K = L - 2447 * J / 80;
		L = J/11;
		J = J+2-12*L;
		I = 100 * (N-49)+I+L;

		year = I;
		month = J;
		day = K;

		cout << year << ' ' << month << ' ' << day << endl;

		return JulianDate(year, month, day, hour, min, sec);
	}

    int getYear() const{
        return year;
    }

    int getMonth() const{
        return month;
    }

    int getDay() const{
        return day;
    }

    int getHour() const{
        return hour;
    }

	int getMin() const{
		return min;
	}

    int getSec() const{
        return sec;
    }

	double getJday() const{
        return jday;
    }

    friend JulianDate operator +(JulianDate a, JulianDate b) {
		double sum = a.jday + b.jday;
		return sum;
    }

	friend JulianDate operator +(JulianDate a, double b) {
		cout << fixed;
		cout << a.jday << endl;
		double jd = a.jday + b;
		cout << jd << endl;
		a = a.convJD(jd);
		return a;
    }

    friend double operator -(JulianDate a, JulianDate b) {
		return a.jday - b.jday;
    }

	friend ostream& operator <<(ostream& s, JulianDate j) {
        s << j.year << ' ' << j.month << ' ' << j.day << ' ' << j.hour << ' ' << 
		j.min << ' ' << j.sec;
        return s;
    }

};

int main() {
	const JulianDate d1(2017, 2, 13, 20, 00, 00);
	const JulianDate d1b(2017, 2, 13, 22, 00, 00);

	cout << d1b - d1 << '\n'; // 2 hours = 2/24 day

	const JulianDate tomorrow = d1 + 1;
	cout << tomorrow; // 2017 2 14 20 00 00
	cout << tomorrow - d1 << '\n';
	// hh:mm:ss  20/24  20/24.0
	const JulianDate d2(2017, 2, 19); // 00:00:00
    const JulianDate d3 = d2 + 3; // what is it 3 days later?
	double days   = d3 - d1;

	int year = d3.getYear();
	int month = d3.getMonth();
	int day = d3.getDay();
	int hour = d3.getHour();
	int min = d3.getMin();
	int sec = d3.getSec();
	cout << d1 << '\n';
	cout << d2 << '\n';
	cout << d3 << '\n';
	cout << year << " " << month << " " << day <<
		hour << " " << min << " " << sec << '\n';
	// Not every operation makes sense!
	//	JulianDate d5 = d3 * d1;
	/*
	JulianDate torture(2017, 2, 27); // 00:00:00
	for (int i = 0; i < 3; i++) {
		cout << torture.getYear() << " " << torture.getMonth() << " " << torture.getDay() << '\n';
		torture = torture + 1;
	}
	*/
}