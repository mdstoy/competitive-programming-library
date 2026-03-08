#include <bits/stdc++.h>
using namespace std;

// verifying: https://atcoder.jp/contests/abc448/submissions/73953869

// use ac-library instead of this when submitting AtCoder
long long pow_mod(long long n, long long p, long long mod) {
    if (p == 0) return 1;
    if (p % 2 == 1) return pow_mod(n, p - 1, mod) * n % mod;
    long long s = pow_mod(n, p / 2, mod);
    return s * s % mod;
}

long long mod_inv(long long x, long long mod) {
    return pow_mod(x, mod - 2, mod);
}
