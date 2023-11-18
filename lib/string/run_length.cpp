#include <bits/stdc++.h>
using namespace std;

// verifying : https://atcoder.jp/contests/abc329/submissions/47738384

vector<pair<char, long long>> run_length(string s) {
    int n = (int)s.size();
    vector<pair<char, long long>> ret;
    long long c = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) c++;
        else {
            ret.emplace_back(s[i - 1], c);
            c = 1;
        }
    }
    ret.emplace_back(s[n - 1], c);
    return ret;
}
