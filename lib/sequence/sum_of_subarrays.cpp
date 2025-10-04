#include <bits/stdc++.h>
using namespace std;

template<typename T> T sum_of_subarrays(vector<T> v) {
    int n = (int)v.size();
    vector<T> sum(n + 1);
    for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + v[i];

    T ret = 0LL;
    for (int i = 0; i <= n; i++) ret += sum[i] * (2LL * i - n);

    return ret;
}

