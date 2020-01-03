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

void print(vector<string> v) {
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
}
