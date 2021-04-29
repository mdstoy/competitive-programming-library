#include <bits/stdc++.h>
using namespace std;

// verifying : https://atcoder.jp/contests/abc006/submissions/22157599

int lis(vector<int> a) {
    int n = (int)a.size();
    vector<int> dp(n, 1 << 30);
    for (int i = 0; i < n; i++) {
        auto itr = lower_bound(dp.begin(), dp.end(), a[i]);
        *itr = a[i];
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == (1 << 30)) break;
        ret++;
    }
    return ret;
}
