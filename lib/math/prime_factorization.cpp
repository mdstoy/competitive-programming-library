#include <bits/stdc++.h>
using namespace std;

// verifying: ???

map<long long, long long> prime_factorization(long long n) {
    map<long long, long long> m;
    long long x = n;
    long long d = 2;
    while (x > 1 && d * d <= n) {
        if (x % d == 0) {
            m[d]++;
            x /= d;
        } else {
            d++;
        }
    }
    if (x != 1) m[x]++;
    return m;
}

