#include <bits/stdc++.h>
using namespace std;

// verifying: https://atcoder.jp/contests/abc223/submissions/49129376

vector<int> topological_sort(vector<vector<int>> g) {
    int n = (int)g.size();
    vector<int> in_depth(n);
    for (int i = 0; i < n; i++) {
        for (auto e : g[i]) {
            in_depth[e]++;
        }
    }
    vector<int> ret;
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
