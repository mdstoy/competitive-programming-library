#include <bits/stdc++.h>
using namespace std;

vector<int> explode(string const & s, char delim) {
    vector<int> result;
    string token;
    for (istringstream iss(s); iss >> token;) result.push_back(stoi(token));
    return result;
}
