#include <bits/stdc++.h>
using namespace std;

using ll = long long;
 
// test with http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4147734#1
// test with https://judge.yosupo.jp/submission/3344

class SegmentTree {
    int n;
    vector<ll> node;

public:
    SegmentTree(vector<ll> v) {
        n = 1;
        int s = v.size();
        while (n < s) n *= 2;
        node.resize(2 * n - 1, 0);
        for (int i = 0; i < s; i++) node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--) node[i] = node[2 * i + 1] + node[2 * i + 2];
    }

    void add(int x, ll val) {
        x += (n - 1);
        node[x] += val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = node[2 * x + 1] + node[2 * x + 2];
        }
    }

    ll find(int a, int b, int k = 0, int l = 0, int r = -1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];

        ll vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }
};
