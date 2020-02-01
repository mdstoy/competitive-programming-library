#include <bits/stdc++.h>
using namespace std;
 
const int INF = 1000000001;

// test with http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4147329#1
// const int INF = INT_MAX;

class SegmentTree {
    int n;
    vector<int> node;

public:
    SegmentTree(vector<int> v) {
        n = 1;
        int s = v.size();
        while (n < s) n *= 2;
        node.resize(2 * n - 1, INF);
        for (int i = 0; i < s; i++) node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--) node[i] = min(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(int x, int val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    int find(int a, int b, int k = 0, int l = 0, int r = -1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return node[k];

        int vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};
