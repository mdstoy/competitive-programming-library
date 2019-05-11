#include <bits/stdc++.h>
using namespace std;

long long gcd(long long m, long long n) {
    return n != 0 ? gcd(n, m % n) : m;
}

long long lcm(long long m, long long n) {
    return m * n / gcd(m, n);
}

bool is_prime(long long n) {
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    }
 
    for (long long i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // expected: 4
    cout << gcd(8, 12) << endl;
    // expected: 24 
    cout << lcm(8, 12) << endl;

    // expected: 2 3 5 7 11 13 17 19....
    for (int i = 1; i <= 100; i++) {
        if (is_prime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}