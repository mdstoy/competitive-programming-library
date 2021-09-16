#include <bits/stdc++.h>
using namespace std;

// verifying : https://atcoder.jp/contests/past201912-open/submissions/25880197

vector<vector<int>> eular_tour(vector<vector<int>> g, int root = 0) {
    vector<vector<int>> ret((int)g.size(), vector<int>(2));

    int idx = 0;
    function<void(int, int)> dfs = [&](int c, int p) {
        ret[c][0] = idx++;
        if (p != -1 and (int)g[c].size() == 1) {
            ret[c][1] = idx++;
            return;
        }

        for (auto e : g[c]) {
            if (e == p) continue;
            dfs(e, c);
        }
        ret[c][1] = idx++;
    };
    dfs(root, -1);

    return ret;
}
