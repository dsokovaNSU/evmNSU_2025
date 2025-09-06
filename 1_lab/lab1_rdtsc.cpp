#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    union tick {
        unsigned long long t64;
        struct {
            unsigned int low, high;
        } t32;
    } start, end;
    
   
    start.t64 = 0;
    end.t64 = 0;
    
    double cpu_Hz = 2900000000ULL; // 2.9 GHz
    
    //int n;
    //cin >> n;
    int n = 2000000000;
    // Барьер памяти перед измерением
    asm volatile("mfence" ::: "memory");
    asm volatile("rdtsc" : "=a"(start.t32.low), "=d"(start.t32.high));
    unsigned long long start_time = start.t64;
    
    double rez = 0;

    for (long long i = 0; i < n; i++) {
        rez += pow(-1, i) / (2 * i + 1);
    }
    
    rez *= 4; 

    // Барьер памяти перед измерением
    asm volatile("mfence" ::: "memory");
    asm volatile("rdtsc" : "=a"(end.t32.low), "=d"(end.t32.high));
    unsigned long long end_time = end.t64;
    
    double time = (end_time - start_time) / cpu_Hz;
    cout << fixed << setprecision(6) << "Time taken: " << time << " sec." << endl;
    
    return 0;
}