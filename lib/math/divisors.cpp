#include <bits/stdc++.h>
using namespace std;

// divisors
// including itself and 1
template<typename T> vector<T> divisors(T n) {
    vector<T> v;
    for (T i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            if (i * i != n) {
                v.push_back(n / i);
            }
        }
    }
    return v;
}
