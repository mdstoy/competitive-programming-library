#include <bits/stdc++.h>
using namespace std;

vector<string> explode(string const & s, char delim) {
    vector<string> result;
    istringstream iss(s);

    for (string token; getline(iss, token, delim);) {
        result.push_back(move(token));
    }
    return result;
}

vector<int> explode2i(string const & s, char delim) {
    vector<int> result;
    istringstream iss(s);

    for (string token; getline(iss, token, delim);) {
        result.push_back(stoi(move(token)));
    }
    return result;
}

// test with https://judge.yosupo.jp/submission/3347
vector<int> z_algorithm(const string& s) {
    int n = s.size();
    vector<int> p(n, 0);
    p[0] = n;
    int i = 1;
    int j = 0;
    while (i < n) {
        while (i + j < n && s[j] == s[i + j]) j++;
        p[i] = j;
        if (j == 0) {
            i++;
            continue;
        }
        int k = 1;
        while (i + k < n && k + p[k] < j) {
            p[i + k] = p[k];
            k++;
        }
        i += k; j -= k;
    }
    return p;
}

template<typename T> void print(vector<T> v) {
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << endl;
    }
}

int main() {
    string s = "This is a test string.";
    vector<string> v = explode(s, ' ');
    print(v);
    s = "";
    v = explode(s, ' ');
    print(v);
    s = "This is a test string.";
    v = explode(s, '.');
    print(v);
    s = "10 3 4 8 20";
    vector<int> w = explode2i(s, ' ');
    print(w);
}
