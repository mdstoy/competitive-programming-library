#include <bits/stdc++.h>
using namespace std;

long long gcd(long long m, long long n) {
    return n != 0 ? gcd(n, m % n) : m;
}

long long lcm(long long m, long long n) {
    return m * n / gcd(m, n);
}

int main() {
    // expect: 4
    cout << gcd(8, 12) << endl;
}