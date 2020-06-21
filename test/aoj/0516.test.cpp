#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../dp/cumulative_sum.cpp"
#undef call_from_test

int main() {
    int n, k;
    vector< long long > ress;
    while (cin >> n >> k) {
        if (n == 0) break;
        vector<long long> nums(n);
        for (int i = 0; i < n; ++i) cin >> nums[i];
        CumulativeSum<long long> cs(nums);
        long long res = numeric_limits<long long>::min();
        for (int i = 0; i <= n - k; ++i) {
            long long val = cs.sum(i, i + k);
            res = max(res, val);
        }
        ress.push_back(res);
    }
    for (long long res : ress) cout << res << endl;
}
