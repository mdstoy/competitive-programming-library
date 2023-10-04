#include <bits/stdc++.h>
using namespace std;

// verifying : https://judge.yosupo.jp/submission/164402

// return {{start-edge, end-edge}, diameter}
pair<pair<int, int>, long long> tree_diameter(vector<vector<pair<int, long long>>> g, int start = 0) {
    int n = (int)g.size();
    vector<long long> dist(n);
 
    function<void(int, int, long long)> dfs = [&](int c, int p, long long d) {
        if (p != -1 and (int)g[c].size() == 1) {
            dist[c] = d;
            return;
        }
 
        for (auto e : g[c]) {
            if (e.first == p) continue;
            dfs(e.first, c, d + e.second);
        }
    };
 
    dfs(start, -1, 0);
 
    int u = -1;
    long long mx = 0;
    for (int i = 0; i < n; i++) {
        if (mx < dist[i]) {
            mx = dist[i];
            u = i;
        }
    }
 
    dist.clear();
    dfs(u, -1, 0);

    int v = -1;
    long long diameter = 0;
    for (int i = 0; i < n; i++) {
        if (diameter < dist[i]) {
            diameter = dist[i];
            v = i;
        }
    }
    
    return make_pair(make_pair(u, v), diameter);
}
