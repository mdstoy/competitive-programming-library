#include <bits/stdc++.h>
using namespace std;

vector<string> explode(string const & s, char delim) {
    vector<string> result;
    string token;
    for (istringstream iss(s); iss >> token;) result.push_back(token);
    return result;
}
