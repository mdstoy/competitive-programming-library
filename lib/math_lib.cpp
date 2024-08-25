#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll m, ll n) {
    return n != 0 ? gcd(n, m % n) : m;
}

ll lcm(ll m, ll n) {
    // If both m and n are large numbers, the result is overflow without parentheses.
    return m * (n / gcd(m, n));
}

ll arithmetic_series(ll n, ll a, ll d = 1) {
    return (2 * a + (n - 1) * d) * n / 2;
}

bool is_prime(ll n) {
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    }
 
    for (ll i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

map<ll, ll> prime_factorization(ll n) {
    map<ll, ll> m;
    ll x = n;
    ll d = 2;
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

int main() {
    // expected: 4
    cout << gcd(8, 12) << endl;
    // expected: 24 
    cout << lcm(8, 12) << endl;
    // expected: 1000000000000000000 
    cout << lcm(1000000000000000000, 500000000000000000) << endl;

    // expected: 2 3 5 7 11 13 17 19....
    for (int i = 1; i <= 100; i++) {
        if (is_prime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    auto factors = prime_factorization(2LL*2*2*3*3*5*7*13*23*1000000007);
    for (auto x : factors) {
        cout << x.first << "(" << x.second << ") | ";
    }
    cout << endl;
}
