#include <bits/stdc++.h>
using namespace std;

template<typename T> vector<bool> eratosthenes(T n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (T i = 2; i * i <= n; i++) {
        if (!is_prime[i]) continue;
        for (T j = i * 2; j <= n; j += i) {
            is_prime[i] = false;
        }
    }
    return is_prime;
}
