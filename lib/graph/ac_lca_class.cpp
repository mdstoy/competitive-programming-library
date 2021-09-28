#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

// already accepted:
// distance at https://atcoder.jp/contests/abc014/submissions/26204523
// lca edge at https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5918921#1

pair<int, int> op(pair<int, int> a, pair<int, int> b) { return min(a, b); }
pair<int, int> e() { return {1000000001, 1000000001}; }

class Lca {
    vector<vector<int>> graph;
    int n;
    vector<int> mn;
    vector<pair<int, int>> depth;
    segtree<pair<int, int>, op, e> st;

    void dfs(int c, int p, int d) {
        depth.emplace_back(d, c);
        if (mn[c] > (int)depth.size() - 1) mn[c] = (int)depth.size() - 1;
        if (p != -1 and (int)graph[c].size() == 1) return;
        for (auto e : graph[c]) {
            if (e == p) continue;
            dfs(e, c, d + 1);
            depth.emplace_back(d, c);
        }
    }

    public:
        Lca(vector<vector<int>> g) {
            graph = g;
            n = (int)g.size();
            mn = vector<int>(n, 1000000001);
            depth = vector<pair<int, int>>();
            dfs(0, -1, 0);
            st = segtree<pair<int, int>, op, e>(depth);
        }

        pair<int, int> prod(int u, int v) {
            int l = mn[u];
            int r = mn[v];
            if (l > r) swap(l, r);
            return st.prod(l, r + 1);
        }

        int lca(int u, int v) {
            auto lca = prod(u, v);
            return lca.second;
        }

        int distance(int u, int v) {
            auto lca = prod(u, v);
            return depth[mn[u]].first - lca.first + depth[mn[v]].first - lca.first + 1;
        }
};
