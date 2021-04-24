#include <bits/stdc++.h>
using namespace std;

// verifying : https://atcoder.jp/contests/typical90/submissions/22039607

int tree_diameter(vector<vector<int>> g, int start) {
    int n = (int)g.size();
    vector<int> dist(n);
 
    function<void(int, int, int)> dfs = [&](int c, int p, int d) {
        if (p != -1 and (int)g[c].size() == 1) {
            dist[c] = d;
            return;
        }
 
        for (auto e : g[c]) {
            if (e == p) continue;
            dfs(e, c, d + 1);
        }
    };
 
    dfs(start, -1, 0);
 
    int u = -1;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (mx < dist[i]) {
            mx = dist[i];
            u = i;
        }
    }
 
    dist.clear();
    dfs(u, -1, 0);
 
    int diameter = 0;
    for (int i = 0; i < n; i++) {
        if (diameter < dist[i]) {
            diameter = dist[i];
            u = i;
        }
    }
    
    return diameter;
}
