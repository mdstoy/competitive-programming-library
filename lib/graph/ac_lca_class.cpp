#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

// already accepted at https://atcoder.jp/contests/abc014/submissions/26192425

int op(int a, int b) { return min(a, b); }
int e() { return 1000000001; }

class Lca {
    vector<vector<int>> graph;
    int n;
    vector<int> mn;
    vector<int> depth;
    segtree<int, op, e> st;

    void dfs(int c, int p, int d) {
        depth.emplace_back(d);
        if (mn[c] > (int)depth.size() - 1) mn[c] = (int)depth.size() - 1;
        if (p != -1 and (int)graph[c].size() == 1) return;
        for (auto e : graph[c]) {
            if (e == p) continue;
            dfs(e, c, d + 1);
            depth.emplace_back(d);
        }
    }

    public:
        Lca(vector<vector<int>> g) {
            graph = g;
            n = (int)g.size();
            mn = vector<int>(n, 1000000001);
            depth = vector<int>();
            dfs(0, -1, 0);
            st = segtree<int, op, e>(depth);
        }

	// get lca of u and v
        int prod(int u, int v) {
            int l = mn[u];
            int r = mn[v];
            if (l > r) swap(l, r);
            return st.prod(l, r + 1);
        }

	// get distance from u to v
        int distance(int u, int v) {
            auto lca = prod(u, v);
            return depth[mn[u]] - lca + depth[mn[v]] - lca + 1;
        }
};

