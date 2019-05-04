#include <bits/stdc++.h>
using namespace std;

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

// cf: https://atcoder.jp/contests/atc002/tasks/atc002_b
int main() {
    long long n, m, p;
    cin >> n >> m >> p;

    vector<int> a(2);

    deque<vector<int>> q;
    q.push_back(a);

    cout << pow_mod(n, p, m) <<endl;
}
