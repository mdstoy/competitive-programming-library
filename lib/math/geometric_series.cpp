#include <bits/stdc++.h>
#include "lib/math/pow_mod.cpp"

using namespace std;

// verifying: https://atcoder.jp/contests/abc448/submissions/73953869

// (1 + r + r^2 + ... + r^(n-1)) mod m
long long geometric_series(long long r, long long n, long long mod) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    long long half = geometric_series(r, n / 2, mod);
    long long total = (half + half * pow_mod(r, n / 2, mod)) % mod;
    if (n % 2 == 1) total = (total * r + 1) % mod;
    return total;
}
