#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

// I was kinda confused about what this assignment was looking for exactly
// I wrote functions analagous to those in the arrayfunc.cc file on github
// that produce the same stats as those in the example, not sure if we were
// supposed to copy the functions exactly or make our own
vector<int> getArray(int& n, vector<int> arrayVec){
    // This function just grabs an array (technically vector)
    // from the hw2f.dat file in the same directory
    int temp;
    ifstream arrayFile;
    string line;
    arrayFile.open("hw2f.dat");
    
    getline(arrayFile, line);
    n = stoi(line);

    arrayVec.resize(n);
    for(int i = 0; i < n; i++){
        getline(arrayFile, line);
        arrayVec[i] = stoi(line);
    }

    arrayFile.close();
    return arrayVec;
}

// Following 3 functions get mean, variance, and min/max for an array
void getMean(int a[], int n, double& mean){
    int sum;
    for(int i = 0; i < n; i++){
        sum = sum + a[i];
    }
    mean = (double)sum / (double)n;
}

void getVar(int a[], int n, double mean, double& var){
    double sum;
    for(int i = 0; i < n; i++){
        sum = sum + pow(((double)a[i] - mean), 2);
    }
    var = sum / n;
}

void getMinMax(int a[], int n, int& min, int& max){
    min = a[0]; 
    max = a[0];
    for(int i = 0; i < n; i++){
        if(a[i] > max)
            max = a[i];
        if(a[i] < min)
            min = a[i];
    }
}

// Function to display statistics about an array. Calls the above statistics functions.
void showStats(int a[], int n, double& mean, double& var, int& min, int& max){
    getMean(a, n, mean);
    getVar(a, n, mean, var);
    getMinMax(a, n, min, max);
    cout << "Array Size: " << n << endl;
    cout << "Mean: " << mean << endl;
    cout << "Variance: " << var << endl;
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
}

// Box function from the example
void box(double xy[], int n, double& xMin, double& xMax, double& yMin, double& yMax){
    xMin = xy[0];
    xMax = xy[0];
    yMin = xy[0];
    yMax = xy[0];
    for(int i=0; i < 2*n-2; i+=2){
        if(xy[i] > xMax)
            xMax = xy[i];
        if(xy[i] < xMin)
            xMin = xy[i];
    }
    for(int k=1; k < 2*n-2; k+=2){
        if(xy[k] > yMax)
            yMax = xy[k];
        if(xy[k] < yMin)
            yMin = xy[k];
    }
}

int main(){
    int n;
    double mean, var;
    int min, max;
    // I used a vector so I could resize the vector inside the function
    // after gettting the value for n rather
    vector<int> arrayVec;
    arrayVec = getArray(n, arrayVec);
    
    // Since the assignment was to use arrays, I coppy the vector into an
    // for the remaining tasks
    int array[n];
    copy(arrayVec.begin(), arrayVec.end(), array);

    // All of the stats are calculated by function calls inside showStats()
    // then the statistics are printed to the console
    cout << "Statistics for array from hw2f.dat file: " << endl;
    showStats(array, n, mean, var, min, max);


    // Initialization and code from arrayfunc.cc github file 
    // not sure if part of assignment
    cout << "Box function demo: " << endl;
   	double points[] = { 1.0,2.5, 2.0,1.5, 3.0,-1.6, -1.5,-2.5, -1,-3.0};
	double xMin, xMax, yMin, yMax;
	box(points, 5, xMin, xMax, yMin, yMax);
	cout << xMin << ' ' << xMax << ' ' << yMin << ' ' << yMax << '\n'; 
}