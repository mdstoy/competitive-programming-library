#include <bits/stdc++.h>
using namespace std;

// verifying: ???

long long arithmetic_series(long long n, long long a, long long d = 1) {
    return (2 * a + (n - 1) * d) * n / 2;
}
