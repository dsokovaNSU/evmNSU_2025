#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n = 2000000000;
    //int n;
    //cin >> n;
    double rez = 0;

    for (long long i = 0; i < n; i++){
        rez += pow(-1, i)/(2*i+1);
    }
    
    rez *= 4; 

    
    return 0;
}