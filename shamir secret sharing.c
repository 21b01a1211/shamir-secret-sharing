/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

long long decode_value(int base, const string &value) {
    return strtoll(value.c_str(), nullptr, base);
}

double lagrange_interpolation(int x[], long long y[], int k) {
    double result = 0.0;
    for (int i = 0; i < k; i++) {
        double term = y[i];
        for (int j = 0; j < k; j++) {
            if (i != j) {
                term *= (0.0 - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return round(result);
}

int main() {
    int x1[] = {1, 2, 3};
    long long y1[] = {
        decode_value(10, "4"),
        decode_value(2, "111"),
        decode_value(10, "12")
    };
    int k1 = 3;
    double c1 = lagrange_interpolation(x1, y1, k1);

    int x2[] = {1, 2, 3, 4, 5, 6, 7};
    long long y2[] = {
        decode_value(6, "13444211440455345511"),
        decode_value(15, "aed7015a346d63"),
        decode_value(15, "6aeeb69631c227c"),
        decode_value(16, "e1b5e05623d881f"),
        decode_value(8, "316034514573652620673"),
        decode_value(3, "2122212201122002221120200210011020220200"),
        decode_value(3, "20120221122211000100210021102001201112121")
    };
    int k2 = 7;
    double c2 = lagrange_interpolation(x2, y2, k2);

    cout << "Secret for Test Case 1: c = " << c1 << endl;
    cout << "Secret for Test Case 2: c = " << c2 << endl;

    return 0;
}


// output:
// Secret for Test Case 1: c = 3
// Secret for Test Case 2: c = -6529208073738502144
