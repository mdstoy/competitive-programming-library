#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define FORR(i, m, n) for (int i = (m); i >= (n); i--)
#define REP(i, n) FOR(i, 0, (n))
#define REPR(i, n) FORR(i, (n) - 1, 0)
#define REP1(i, n) FOR(i, 1, (n) + 1)
#define REPS(c, s) for (char c : s)
#define ALL(c) (c).begin(), (c).end()
#define sz(v) (int)v.size()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
const int MOD = 1000000007;
const int INF = 1000000001;
const ll LINF = 1000000001000000001LL;
const char EOL = '\n';
 
void solve();
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(numeric_limits<double>::max_digits10);
    solve();
    return 0;
}

class UnionFind {
    vector<int> parent;

    public:
        UnionFind(int size) {
            parent = vector<int>(size, -1);
        }

        int find(int x) {
            if (parent[x] < 0) {
                // parent itself
                return x;
            } else {
                return parent[x] = find(parent[x]);
            }
        }

        bool unite(int x, int y) {
            int rX, rY;
            if ((rX = find(x)) == (rY = find(y))) {
                // already united
                return false;
            }
            if (size(rX) < size(rY)) {
                int tmp = rX;
                rX = rY;
                rY = tmp;
            }
            parent[rX] += parent[rY];
            parent[rY] = rX;
            return true;
        }

        int size(int x) {
            return -parent[find(x)];
        }

        bool is_same(int x, int y) {
            return find(x) == find(y);
        }

        int component_count() {
            int c = 0;
            for (const int x : parent) {
                if (x < 0) {
                    c++;
                }
            }
            return c;
        }
};

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    REP(i, m) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    reverse(ALL(a));
    reverse(ALL(b));
    UnionFind uf(n);
    vector<ll> ans(m + 1);
    ans[0] = n * (n - 1) / 2;
    REP1(i, m) {
        bool b0 = uf.is_same(a[i - 1], b[i - 1]);
        ll b1 = uf.size(a[i - 1]);
        ll b2 = uf.size(b[i - 1]);
        uf.unite(a[i - 1], b[i - 1]);
        if (b0) ans[i] = ans[i - 1];
        else ans[i] = ans[i - 1] - (b1 * b2);
    }
    reverse(ALL(ans));
    REP1(i, m) cout << ans[i] << EOL;
}

