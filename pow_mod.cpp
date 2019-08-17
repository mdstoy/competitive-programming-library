#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll pow_mod(ll n, ll p, ll mod) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 1) {
        return pow_mod(n, p - 1, mod) * n % mod;
    } else {
        ll s = pow_mod(n, p / 2, mod);
        return s * s % mod;
    }
}

// cf: https://atcoder.jp/contests/atc002/tasks/atc002_b
int main() {
    ll n, m, p;
    cin >> n >> m >> p;

    vector<int> a(2);

    deque<vector<int>> q;
    q.push_back(a);

    cout << pow_mod(n, p, m) <<endl;
}
