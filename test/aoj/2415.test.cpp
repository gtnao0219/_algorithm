#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../dp/knuth_yao_speedup.cpp"
#include "../../dp/cumulative_sum.cpp"
#undef call_from_test

int main() {
    int n; cin >> n;
    vector<long long> w(n);
    for(int i = 0; i < n; ++i) cin >> w[i];
    CumulativeSum<long long> cs(w);
    auto costF = [&](int i, int k, int j) {
        return cs.sum(i, j + 1);
    };
    cout << knuthYaoSpeedup<long long>(n, costF) << endl;
}