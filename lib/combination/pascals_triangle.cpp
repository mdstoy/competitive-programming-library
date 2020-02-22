#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define REP(i, n) FOR(i, 0, (n))

// combi[n][k] means nCk
vector<vector<ll>> pascals_triangle(int n) {
    vector<vector<ll>> combi(n + 1, vector<ll>(n + 1));
    REP(i, n + 1) REP(j, i + 1) {
        if (j == 0 || j == i) combi[i][j] = 1LL;
        else combi[i][j] = combi[i - 1][j - 1] + combi[i - 1][j];
    }
    return combi;
}

int main() {
    // Pascal's triangle
    auto tri = pascals_triangle(50);
    REP(i, 21) {
        REP(j, i + 1) {
            cout << tri[i][j] << " ";
        }
        cout << endl;
    }
}
