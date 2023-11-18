#include <bits/stdc++.h>
using namespace std;

// verifying : https://atcoder.jp/contests/arc130/submissions/27771431

vector<long long> run_length(string s) {
    int n = (int)s.size();
    vector<long long> ret;
    long long c = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) c++;
        else {
            ret.emplace_back(c);
            c = 1;
        }
    }
    ret.emplace_back(c);
    return ret;
}
