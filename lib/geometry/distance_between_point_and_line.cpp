#include <bits/stdc++.h>
using namespace std;

// verifing: https://atcoder.jp/contests/math-and-algorithm/submissions/30698379

// *** CAUTION *** : Return value is square.
double distance_between_point_and_line(double x1, double y1, double x2, double y2, double x0, double y0) {
    double a = x2 - x1;
    double b = y2 - y1;
    double c = a * a + b * b;
    double d = -(a * (x1 - x0) + b * (y1 - y0));
    if (d < 0) {
        return (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
    } else if (d > c) {
        return (x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0);
    } else {
        double e = a * (y1 - y0) - b * (x1 - x0);
        return e * e / c;
    }
}
