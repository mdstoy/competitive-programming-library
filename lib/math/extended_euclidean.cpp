#include <bits/stdc++.h>
using namespace std;

// verifying: https://atcoder.jp/contests/abc340/submissions/50190150

pair<long long, long long> extgcd(long long a, long long b) {
    if (b == 0) return {1, 0};
    auto [y, x] = extgcd(b, a % b);
    y -= a / b * x;
    return make_pair(x, y);
}
