#include <iostream>
#include <sys/times.h>
#include <unistd.h>
#include <cmath>
#include <iomanip>


using namespace std;

int main(){
    struct tms start, end;
    long clocks_per_sec = sysconf(_SC_CLK_TCK);
    long clocks;
    int n = 2000000000;
    
    //int n = 1000000;
    //int n;
    //cin >> n;
    double rez = 0;
    
    times(&start);
    for (long long i = 0; i < n; i++){
        rez += pow(-1, i)/(2*i+1);
    }
    
    rez *= 4; 
    times(&end);

    clocks = end.tms_utime - start.tms_utime;
    
    cout << fixed << setprecision(6) << "Time taken: " << (double)clocks / clocks_per_sec << " sec." << endl;
    return 0;
}
