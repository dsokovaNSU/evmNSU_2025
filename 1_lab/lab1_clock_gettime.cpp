#include <iostream>
#include <cmath>
#include <time.h>
#include <iomanip>

using namespace std;

int main() {
    struct timespec start, end;
    
    int n = 2000000000;
    //int n;
    //cin >> n;
    double rez = 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    for (long long i = 0; i < n; i++){
        rez += pow(-1, i)/(2*i+1);
    }
    
    rez *= 4; 
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    cout << fixed << setprecision(6) << "Time taken: " << end.tv_sec-start.tv_sec + 0.000000001*(end.tv_nsec-start.tv_nsec) << " sec." << endl;
    return 0;
}