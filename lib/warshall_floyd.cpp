#include <bits/stdc++.h>
using namespace std;

#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define REP(i, n) FOR(i, 0, (n))
#define sz(v) (int)v.size()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}

// already accepted at https://atcoder.jp/contests/abc143/submissions/8052790

template<typename T> vector<vector<T>> pre_warshall_floyd(int n, T inf) {
    vector<vector<T>> g(n, vector<T>(n, inf));
    REP(i, n) g[i][i] = 0;
    return g;
}

template<typename T> void warshall_floyd(vector<vector<T>>& g) {
    int n = sz(g);
    REP(k, n) REP(i, n) REP(j, n) chmin(g[i][j] ,g[i][k] + g[k][j]);
}

template<typename T> vector<int> restore_path(int start, int end, vector<vector<T>>& aggregated, vector<vector<T>>& origin) {
    int n = sz(g);
    vector<int> p;
    int curr = start;
    while (curr != end) {
        REP(i, n) {
            // if
            // (curr)---h[curr][i]---(i)---g[i][end]---(end)
            // and
            // (curr)-----------g[curr][end]-----------(end)
            // match,
            // "i" is the edge included in the shortest path.
            if (i != curr && origin[curr][i] + aggregated[i][end] == aggregated[curr][end]) {
                curr = i;
                p.push_back(i);
                break;
            }
        }
    }
    return p;
}

