#include <bits/stdc++.h>
using namespace std;

// verifying : https://atcoder.jp/contests/typical90/submissions/22039607

vector<vector<int>> make_tree(int n, bool origin1 = true) {
    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        if (origin1) {
            u--;
            v--;
        }
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    return g;
}
