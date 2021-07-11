#include <bits/stdc++.h>
using namespace std;

// combi[n][k] means nCk
vector<vector<long long>> pascals_triangle(int n) {
    vector<vector<long long>> combi(n + 1, vector<long long>(n + 1));
    for (int i = 0; i <= n; i++) for (int j = 0; j <= i; j++) {
        if (j == 0 || j == i) combi[i][j] = 1LL;
        else combi[i][j] = combi[i - 1][j - 1] + combi[i - 1][j];
    }
    return combi;
}

int main() {
    // Pascal's triangle
    auto tri = pascals_triangle(50);
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j <= i; j++) {
            cout << tri[i][j] << " ";
        }
        cout << endl;
    }
}
