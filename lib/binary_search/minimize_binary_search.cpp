#include <bits/stdc++.h>
using namespace std;

// already accepted at https://atcoder.jp/contests/exawizards2019/submissions/8652435
// usage : BinarySearch<type> bs(left, right, lambda);
// ex : BinarySearch<ll> bs(-1LL, LINF, lambda);

template<typename D> class BinarySearch {
    D left;
    D right;
    function<bool(D)> func;

    public:
        BinarySearch(D l, D r, function<bool(D)> f) {
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
