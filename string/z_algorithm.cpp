#include<bits/stdc++.h>
using namespace std;

/*
  // Overview
  lcp s and s[i:]

  // Time complexity
  O(|s|)
*/
vector<int> z_algorithm(string s) {
    int n = s.size();
    vector<int> res(n, 0);
    res[0] = n;
    int i = 1, j = 0;
    while (i < n) {
        while (i + j < n && s[j] == s[i + j]) ++j;
        res[i] = j;
        if (j == 0) {
            ++i;
            continue;
        }
        int k = 1;
        while (i + k < n && k + res[k] < j) {
            res[i+k] = res[k];
            ++k;
        }
        i += k;
        j -= k;
    }
    return res;
}

/*
    verified https://judge.yosupo.jp/problem/zalgorithm
*/
int main() {
    string S; cin >> S;
    auto res = z_algorithm(S);
    cout << res[0];
    for (int i = 1; i < res.size(); ++i) {
        cout << " " << res[i];
    }
    cout << endl;
}
