#include <bits/stdc++.h>
using namespace std;

template <typename T> bool next_combination(const T first, const T last, int k) {
    const T subset = first + k;
    // empty container | k = 0 | k == n 
    if (first == last || first == subset || last == subset) {
        return false;
    }
    T src = subset;
    while (first != src) {
        src--;
        if (*src < *(last - 1)) {
            T dest = subset;
            while (*src >= *dest) {
                dest++;
            }
            iter_swap(src, dest);
            rotate(src + 1, dest + 1, last);
            rotate(subset, subset + (last - dest) - 1, last);
            return true;
        }
    }
    // restore
    rotate(first, subset, last);
    return false;
}

void test(vector<int>& v, int k) {
    do {
        for (int i = 0; i < k; i++) {
            cout << v[i] << " ";
        }
        cout << "| ";
        for (int i = k; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    } while(next_combination(v.begin(), v.end(), k));
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7};
    cout << "expected: a list of 7C3" << endl;
    test(v, 3);
    cout << "expected: 1 2 3 4 5 6 7 |" << endl;
    test(v, 7);
    cout << "expected: | 1 2 3 4 5 6 7" << endl;
    test(v, 0);
    // unexpected
    // test(v, 8);
    vector<int> w{1};
    // | 1
    test(w, 0);
    // 1 |
    test(w, 1);
    // unexpected
    // test(w, 2);
    vector<int> x{};
    test(x, 0);
    // Segmentation fault
    // test(x, 1); 
}
