#include <bits/stdc++.h>
using namespace std;

// verifying: https://atcoder.jp/contests/abc223/submissions/26656922

vector<int> topological_sort(vector<vector<int>> g, vector<int> in_depth) {
    vector<int> ret;
    int n = (int)g.size();
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_depth[i] == 0) {
            q.push(-i);
        }
    }
    while (!q.empty()) {
        int p = -q.top();
        q.pop();
        ret.emplace_back(p);
        for (auto e : g[p]) {
            in_depth[e]--;
            if (in_depth[e] == 0) {
                q.push(-e);
            }
        }
    }
    return ret;
}
