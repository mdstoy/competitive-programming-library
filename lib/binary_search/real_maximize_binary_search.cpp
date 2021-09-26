#include <bits/stdc++.h>
using namespace std;

// already accepted at https://algo-method.com/submissions/87640
// usage : BinarySearch<type> bs(left, right, lambda);
// ex : BinarySearch<double> bs(0.0, 1000.0, lambda);

template<typename D, class... A> class BinarySearch {
    D left;
    D right;
    function<bool(D, A...)> func;
    D eps;
    // NOTE: adjust the limiter
    int limiter;

    public:
        BinarySearch(D l, D r, function<bool(D, A...)> f, D e = DBL_EPSILON, int limit = 100) {
            left = l;
            right = r;
            func = f;
            eps = e;
            limiter = limit;
        }

        D calc(A... args) {
            // NOTE: adjust the epsilon
            while (right - left > eps) {
                D middle = (left + right) / 2;
                if (func(middle, args...)) {
                    left = middle;
                } else {
                    right = middle;
                }
                if (--limiter < 0) break;
            }
            return left;
        }
};
