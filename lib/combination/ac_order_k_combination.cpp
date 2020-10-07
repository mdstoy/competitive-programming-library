#include <atcoder/all>
using namespace atcoder;

#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define REP1(i, n) FOR(i, 1, (n) + 1)

using mint = modint1000000007;

mint nck(int n, int k) {
    if (n - k < k) k = n - k;
    mint ret(1);
    REP1(i, k) ret *= ((n - i + 1) * mint(i).inv());
    return ret;
}

