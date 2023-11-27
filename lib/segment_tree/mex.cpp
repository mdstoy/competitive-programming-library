#include <bits/stdc++.h>
using namespace std;
 
// verifing: https://atcoder.jp/contests/abc330/submissions/47996609

const int INF = 1000000001;

class SegmentTree {
    vector<int> org;
    int mx;
    int n;
    vector<int> node;

public:
    SegmentTree(vector<int> src) {
        org = src;
        mx = (int)org.size() + 1;
        n = 1;
        while (n < mx) n *= 2;
        node.resize(2 * n - 1, 0);
        for (int i = 0; i < mx - 1; i++) if (org[i] <= mx) increment(org[i]);
    }

    void replace(int x, int val) {
        if (org[x] <= mx) decrement(org[x]);
        org[x] = val;
        if (org[x] <= mx) increment(org[x]);
    }

    void increment(int x) {
        x += (n - 1);
        node[x]++;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    void decrement(int x) {
        x += (n - 1);
        node[x]--;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    pair<int, int> find_with_min_index(int a, int b, int k = 0, int l = 0, int r = -1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return make_pair(INF, INF);
        if(k >= n - 1) return make_pair(node[k], k - n + 1);

        if (node[2 * k + 1] <= node[2 * k + 2]) return find_with_min_index(a, b, 2 * k + 1, l, (l + r) / 2);
        else return find_with_min_index(a, b, 2 * k + 2, (l + r) / 2, r);
    }

    int mex() {
        if (node[1] <= node[2]) return find_with_min_index(0, mx, 1, 0, n / 2).second;
        else return find_with_min_index(0, mx, 2, n / 2, n).second;
    }
};
