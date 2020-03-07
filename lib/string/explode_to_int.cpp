#include <bits/stdc++.h>
using namespace std;

vector<int> explode2i(string const & s, char delim) {
    vector<int> result;
    istringstream iss(s);

    for (string token; getline(iss, token, delim);) {
        result.push_back(stoi(move(token)));
    }
    return result;
}
