#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define REP(i, n) FOR(i, 0, (n))

// use ac-library instead of this when submitting AtCoder
long long pow_mod(long long n, long long p, long long mod) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 1) {
        return pow_mod(n, p - 1, mod) * n % mod;
    } else {
        long long s = pow_mod(n, p / 2, mod);
        return s * s % mod;
    }
}

// use ac-library instead of this when submitting AtCoder
long long mod_inv(long long x, long long mod) {
    return pow_mod(x, mod - 2, mod);
}

ll calc_mod(string s, ll d) {
    ll r = 0;
    REP(i, (int)s.size()) r = (r * 10 + (s[i] - '0')) % d;
    return r;
}

vector<ll> mod_inverses(ll n, ll m) {
    vector<ll> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = inv[m % i] * (m - m / i) % m;
    return inv;
}

int main() {
    // cf: https://atcoder.jp/contests/atc002/tasks/atc002_b
    ll n, m, p;
    cin >> n >> m >> p;

    vector<int> a(2);

    deque<vector<int>> q;
    q.push_back(a);

    cout << pow_mod(n, p, m) << endl;

    // expected : 2
    cout << calc_mod("999999999999999999999999998", 3) << endl;
    // expected : 3
    cout << calc_mod("1000000000000000000000000000000000000000000000000000000000003", 5) << endl;
    // expected : 123456789123456789
    cout << calc_mod("10000000000000000000000000000000000000000000000000000000000123456789123456789", 1000000000000000000LL) << endl;
}
