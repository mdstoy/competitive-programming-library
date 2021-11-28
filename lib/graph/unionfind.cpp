#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> parent;
    int count;

    public:
        UnionFind(int size) {
            parent = vector<int>(size, -1);
            count = size;
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
            count--;
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
            return count;
        }
};

// cf: https://atcoder.jp/contests/atc001/tasks/unionfind_a
int main() {
    int n, q, p, a, b;
    cin >> n >> q;
    UnionFind uf = UnionFind(n);
    for (int i = 0; i < q; i++) {
        cin >> p >> a >> b;
        if (p == 0) {
            uf.unite(a, b);
        } else {
            cout << (uf.is_same(a, b) ? "Yes" : "No") <<endl;
        }
    }
    // expect: 5 | {0}, {1, 2, 3, 4}, {5}, {6}, {7}
    cout << uf.component_count() << endl;
}

