#include <bits/stdc++.h>
using namespace std;

// already accepted at https://atcoder.jp/contests/exawizards2019/submissions/11618977
// usage : BinarySearch<type> bs(left, right, lambda);
// ex : BinarySearch<ll> bs(-1LL, LINF, lambda);

template<typename D, class... A> class BinarySearch {
    D left;
    D right;
    function<bool(D, A...)> func;

    public:
        BinarySearch(D l, D r, function<bool(D, A...)> f) {
            left = l;
            right = r;
            func = f;
        }

        D calc(A... args) {
            while (abs(right - left) > 1) {
                D middle = (left + right) / 2;
                if (func(middle, args...)) {
                    left = middle;
                } else {
                    right = middle;
                }
            }
            return left;
        }
};
