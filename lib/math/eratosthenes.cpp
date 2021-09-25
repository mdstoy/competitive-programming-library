#include <bits/stdc++.h>
using namespace std;

// sieve of Eratosthenes
template<typename T> vector<bool> eratosthenes(T n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (T i = 2; i * i <= n; i++) {
        if (!is_prime[i]) continue;
        for (T j = i * 2; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
    return is_prime;
}

// interval ([m, n]) sieve of Eratosthenes
// prerequisite: m <= n
template<typename T> vector<bool> eratosthenes(T m, T n) {
    vector<bool> is_prime(n + 1 - m, true);

    for (T i = 2; i * i <= n; i++) {
        for (T j = (m + i - 1) / i; i * j <= n; j++) {
            // keep state when it is a prime number
			if (i == i * j) continue;
            is_prime[i * j - m] = false;
        }
    }
    return is_prime;
}
