
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1000000001;
const ll LINF = 1000000001000000001LL;

// FIXME : need to refactor
inline vector<int> get_d(int n) {return vector<int>(n, INF);}
inline vector<ll> get_d(ll n) {return vector<ll>(n, LINF);}
template<typename T> vector<T> dijkstra(int s, vector<vector<pair<int, T>>>& g) {
    T n = sz(g);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
    vector<T> d = get_d(n);
    d[s] = 0;
    q.emplace(0, s);

    while (!q.empty()) {
        pair<T, int> p = q.top();
        q.pop();
        int v = p.second;
        if (d[v] < p.first) continue;

        for (auto x : g[v]) {
            if (d[x.first] > d[v] + x.second) {
                d[x.first] = d[v] + x.second;
                q.emplace(d[x.first], x.first);
            }
        }
    }
    return d;
}
