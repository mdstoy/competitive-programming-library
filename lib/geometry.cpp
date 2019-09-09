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
}