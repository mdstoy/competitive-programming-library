#include <bits/stdc++.h>
using namespace std;

// verifying : https://onlinejudge.u-aizu.ac.jp/status/users/mdstoy/submissions/1/ALDS1_10_C/judge/5433717/C++17

int lcs(string s, string t) {
    int n = sz(s);
    int m = sz(t);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
            else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    return dp[n][m];
}
