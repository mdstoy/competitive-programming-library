#include <bits/stdc++.h>
using namespace std;

/*
 * the intersection of two lines
 * 
 * @return pair<double, double> | first: coordinate of x / second: coordinate of y
 */
pair<double, double> intersection(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy) {
    // 0, a / x, b / sx, sy / tx, ty
    double s1 = ((dx - cx) * (ay - cy) - (dy - cy) * (ax - cx)) / 2;
    double s2 = ((dx - cx) * (cy - by) - (dy - cy) * (cx - bx)) / 2;
    double x = ax + (bx - ax) * s1 / (s1 + s2);
    double y = ay + (by - ay) * s1 / (s1 + s2);
    return make_pair(x, y);
}

/*
 * CAUTION : Return value is square.
 */
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

int main() {
    // expect 5, 5
    auto x = intersection(0, 0, 10, 10, 0, 10, 10, 0);
    cout << x.first << ", " << x.second << endl;
    
    // expect 5, 5
    x = intersection(3, 3, 6, 9, 5, 10, 7, 2);
    cout << x.first << ", " << x.second << endl;

    // -nan, inf (parallel)
    x = intersection(3, 3, 3, 10, 5, 5, 5, 100);
    cout << x.first << ", " << x.second << endl;

    // -inf, -nun (parallel)
    x = intersection(3, 3, 10, 3, 5, 5, 100, 5);
    cout << x.first << ", " << x.second << endl;

    // -inf, -inf (parallel)
    x = intersection(3, 3, 6, 6, 0, 3, 3, 6);
    cout << x.first << ", " << x.second << endl;

    cout << sqrt(distance_between_point_and_line(0.0, 0.0, 10.0, 10.0, 8.0, 2.0)) << endl;
}