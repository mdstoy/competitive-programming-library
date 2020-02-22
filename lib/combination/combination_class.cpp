#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Combination {
    vector<ll> factorial;
    vector<ll> fact_inverse;
    vector<ll> inverse;
    int mod;

    void init(int size) {
        factorial[0] = 1;
        factorial[1] = 1;
        fact_inverse[0] = 1;
        fact_inverse[1] = 1;
        inverse[1] = 1;

        for (int i = 2; i < size; i++) {
            factorial[i] = factorial[i - 1] * i % mod;
            inverse[i] = mod - inverse[mod % i] * (mod / i) % mod;
            fact_inverse[i] = fact_inverse[i - 1] * inverse[i] % mod;
        }
    }

    public:
        Combination(int size, int m) {
           factorial = vector<ll>(size);
           fact_inverse = vector<ll>(size);
           inverse = vector<ll>(size);
           mod = m;
           init(size);
        }
    
        ll calc(int n, int k) {
            if (n < k) {
                return 0;
            }
            if (n < 0 || k < 0) {
                return 0;
            }
            return factorial[n] * (fact_inverse[k] * fact_inverse[n - k] % mod) % mod;
        }

        // i.e. nHk
        ll with_repetition(int n, int k) {
            return calc(n + k - 1, k);
        }
};

int main() {
    // Combination class (counting)
    Combination combi = Combination(500000, 1000000007);
    cout << combi.calc(5, 3) << endl;
    cout << combi.calc(10000, 5000) << endl;

    // expected 15
    cout << combi.with_repetition(5, 2) << endl;
    // expected 6 
    cout << combi.with_repetition(3, 2) << endl;
}
