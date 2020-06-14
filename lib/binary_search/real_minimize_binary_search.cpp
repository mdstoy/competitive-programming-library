#include <bits/stdc++.h>
using namespace std;

// already accepted at https://atcoder.jp/contests/judge-update-202004/submissions/11618809
// and https://atcoder.jp/contests/exawizards2019/submissions/11618977
// usage : BinarySearch<type[, type...]> bs(left, right, lambda);
// ex : BinarySearch<ll, ll> bs(-1LL, LINF, lambda);

template<typename D, class... A> class BinarySearch {
    D left;
    D right;
    function<bool(D, A...)> func;
    // NOTE: adjust the limiter
    int limiter = 100;

    public:
        BinarySearch(D l, D r, function<bool(D, A...)> f) {
            left = l;
            right = r;
            func = f;
        }

        D calc(A... args) {
            // NOTE: adjust the epsilon
            while (right - left > DBL_EPSILON) {
                D middle = (left + right) / 2;
                if (func(middle, args...)) {
                    right = middle;
                } else {
                    left = middle;
                }
                if (--limiter < 0) break;
            }
            return right;
        }
};
