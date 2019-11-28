#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define REP(i, n) FOR(i, 0, (n))

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

        ll with_repetition(int n, int k) {
            return calc(n + k - 1, k);
        }
};

template <typename T> bool next_combination(const T first, const T last, int k) {
    const T subset = first + k;
    // empty container | k = 0 | k == n 
    if (first == last || first == subset || last == subset) {
        return false;
    }
    T src = subset;
    while (first != src) {
        src--;
        if (*src < *(last - 1)) {
            T dest = subset;
            while (*src >= *dest) {
                dest++;
            }
            iter_swap(src, dest);
            rotate(src + 1, dest + 1, last);
            rotate(subset, subset + (last - dest) - 1, last);
            return true;
        }
    }
    // restore
    rotate(first, subset, last);
    return false;
}

vector<vector<ll>> pascals_triangle(int n) {
    vector<vector<ll>> combi(n + 1, vector<ll>(n + 1));
    REP(i, n + 1) REP(j, i + 1) {
        if (j == 0 || j == i) combi[i][j] = 1LL;
        else combi[i][j] = combi[i - 1][j - 1] + combi[i - 1][j];
    }
    return combi;
}

void test(vector<int>& v, int k) {
    do {
        for (int i = 0; i < k; i++) {
            cout << v[i] << " ";
        }
        cout << "| ";
        for (int i = k; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    } while(next_combination(v.begin(), v.end(), k));
}

int main() {

    // next_combination

    vector<int> v{1, 2, 3, 4, 5, 6, 7};
    cout << "expected: a list of 7C3" << endl;
    test(v, 3);
    cout << "expected: 1 2 3 4 5 6 7 |" << endl;
    test(v, 7);
    cout << "expected: | 1 2 3 4 5 6 7" << endl;
    test(v, 0);
    // unexpected
    // test(v, 8);
    vector<int> w{1};
    // | 1
    test(w, 0);
    // 1 |
    test(w, 1);
    // unexpected
    // test(w, 2);
    vector<int> x{};
    test(x, 0);
    // Segmentation fault
    // test(x, 1); 

    // Combination class (counting)
    Combination combi = Combination(500000, 1000000007);
    cout << combi.calc(5, 3) << endl;
    cout << combi.calc(10000, 5000) << endl;

    // expected 15
    cout << combi.with_repetition(5, 2) << endl;
    // expected 6 
    cout << combi.with_repetition(3, 2) << endl;

    // Pascal's triangle
    auto tri = pascals_triangle(50);
    REP(i, 21) {
        REP(j, i + 1) {
            cout << tri[i][j] << " ";
        }
        cout << endl;
    }
}
