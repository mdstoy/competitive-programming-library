#include <bits/stdc++.h>
using namespace std;

// verifying : https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5685269#1

int levenshtein(const string &s, const string &t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int i = 0; i <= m; i++) dp[0][i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i + 1][j + 1] = min(min(dp[i][j + 1], dp[i + 1][j]) + 1, dp[i][j] + (s[i] == t[j] ? 0 : 1));
        }
    }

    return dp[n][m];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << levenshtein(s1, s2) << endl;
}
