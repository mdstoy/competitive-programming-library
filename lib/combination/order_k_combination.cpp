#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define REP1(i, n) FOR(i, 1, (n) + 1)

vector<ll> list_mod_inverse(ll n, ll m) {
    vector<ll> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i)
        inv[i] = inv[m % i] * (m - m / i) % m;
    return inv;
}

ll nck(ll n, ll k, ll m, vector<ll>& inv) {
    if (n - k < k) k = n - k;
    ll ret = 1;
    REP1(i, k) {
        ret *= ((n - i + 1) * inv[i]) % m;
        ret %= m;
    }
    return ret;
}

int main() {
    const int MOD = 1000000007;
    auto inv = list_mod_inverse(200000, MOD);
    cout << nck(7, 3, MOD, inv) << endl;
    cout << nck(1000000000, 200000, MOD, inv) << endl;
}