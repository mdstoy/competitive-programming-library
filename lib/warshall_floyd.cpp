#include <bits/stdc++.h>
using namespace std;

#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define REP(i, n) FOR(i, 0, (n))
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}

// already accepted at https://atcoder.jp/contests/abc143/submissions/8052790

template<typename T> vector<vector<T>> pre_warshall_floyd(int n, T inf) {
    vector<vector<T>> g(n, vector<T>(n, inf));
    REP(i, n) g[i][i] = 0;
    return g;
}

template<typename T> void warshall_floyd(vector<vector<T>>& g) {
    REP(k, n) REP(i, n) REP(j, n) chmin(g[i][j] ,g[i][k] + g[k][j]);
}
