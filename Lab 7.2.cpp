#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <vector>
using namespace std;
#define distance(x1, y1, x2, y2) (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
double square(double x1, double y1, double x2, double y2, double x3, double y3) {
    double l1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)), l2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)), l3 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    double p = (l1 + l2 + l3) / 2;
    return sqrt(p * (p - l1) * (p - l2) * (p - l3));
}
double squaren(int n, ...) {
    vector <double> a; vector <double> a1; double s = 0.0; double s1 = 0.0;
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; ++i) {
        double val = va_arg(args, double);
        if (i % 2 == 0) a.push_back(val);
        else a1.push_back(val);
    }
    va_end(args);
    for (int i = 0; i < a.size(); i++) {
        if (i == a.size() - 1) s = s + a[i] * a1[0];
        else s = s + a[i] * a1[i + 1];
    }
    for (int i = 0; i < a1.size(); i++) {
        if (i == a1.size() - 1) s1 = s1 + a1[i] * a[0];
        else s1 = s1 + a1[i] * a[i + 1];
    }
    return abs(s - s1) / 2.0;
}
int main() {
    cout << squaren(10, 3.0, 4.0, 5.0, 11.0, 12.0, 8.0, 9.0, 5.0, 5.0, 6.0) << endl;
    cout << distance(1.0, 3.0, 5.0, 8.0);
    cout << endl << square(3.0, 4.0, 5.0, 11.0, 12.0, 8.0);
    return 0;
}