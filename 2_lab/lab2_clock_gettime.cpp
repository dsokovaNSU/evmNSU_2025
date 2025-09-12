#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <cstdlib> 

using namespace std;

int main(int argc, char* argv[]) {
    struct timespec start, end;
    
    long long n=2000000000;
    if (argc == 2) {
        n = atoll(argv[1]); // преобразуем строку в long long
    }
    long double rez = 0;

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    for (long long i = 0; i < n; i++){
        rez += pow(-1, i)/(2*i+1);
    }
    
    rez *= 4; 
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    
    cout << fixed << setprecision(3) << "Time taken: " << end.tv_sec-start.tv_sec + 0.000000001*(end.tv_nsec-start.tv_nsec) << " sec." << endl;
    cout << fixed << setprecision(30) << rez << endl;
    return 0;
}
