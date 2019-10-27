#include <bits/stdc++.h>
using namespace std;

// already accepted at https://atcoder.jp/contests/abc144/submissions/8181967

template<typename D, typename F> class BinarySearch {
    D left;
    D right;
    F func;

    public:
        BinarySearch(D l, D r, F f) {
            left = l;
            right = r;
            func = f;
        }

        D calc() {
            while (abs(right - left) > 1) {
                D m = (left + right) / 2;
                if (func(m)) {
                    right = m;
                } else {
                    left = m;
                }
            }
            return right;
        }
};
