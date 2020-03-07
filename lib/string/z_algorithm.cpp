#include <bits/stdc++.h>
using namespace std;

// test with https://judge.yosupo.jp/submission/3347
vector<int> z_algorithm(const string& s) {
    int n = s.size();
    vector<int> p(n, 0);
    p[0] = n;
    int i = 1;
    int j = 0;
    while (i < n) {
        while (i + j < n && s[j] == s[i + j]) j++;
        p[i] = j;
        if (j == 0) {
            i++;
            continue;
        }
        int k = 1;
        while (i + k < n && k + p[k] < j) {
            p[i + k] = p[k];
            k++;
        }
        i += k; j -= k;
    }
    return p;
}
