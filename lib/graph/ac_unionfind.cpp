#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

class UnionFind {
    dsu uf;
    int count;

    public:
        UnionFind(int size) : uf(size), count(size) {}

        int find(int x) { return uf.leader(x); }

        int unite(int x, int y) {
            if (!uf.same(x, y)) count--;
            return uf.merge(x, y);
        }

        int size(int x) { return uf.size(x); }

        bool is_same(int x, int y) { return uf.same(x, y); }

        vector<vector<int>> groups() { return uf.groups(); }

        int component_count() { return count; }
};
