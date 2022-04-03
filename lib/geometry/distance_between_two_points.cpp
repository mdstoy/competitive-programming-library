#include <bits/stdc++.h>
using namespace std;

// verifing: https://atcoder.jp/contests/math-and-algorithm/submissions/30698630

// *** CAUTION *** : Return value is square.
double distance_between_two_points(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
