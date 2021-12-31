#include <bits/stdc++.h>
using namespace std;

long long basek2decimal(string s, int k) {
    reverse(s.begin(), s.end());
    int ret = 0;
    int d = 0;
    function<int(char)> f = [](char c) {return (c >= 0 and c <= 9 ? (int)(c - '0') : (int)(c - 'a') + 10);};
    for (char c : s) ret += (long long)pow(k, d++) * f(c);
    return ret;
}
