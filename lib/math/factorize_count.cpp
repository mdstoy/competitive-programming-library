#include <bits/stdc++.h>
using namespace std;

// verifying: https://atcoder.jp/contests/abc368/submissions/57121829

int factorize_count(int n) {
    int p = 0;
    int x = n;
    int d = 2;
    while (x > 1 && d * d <= n) {
        if (x % d == 0) {
            p++;
            x /= d;
        } else {
            d++;
        }
    }
    if (x != 1) p++;
    return p;
}

