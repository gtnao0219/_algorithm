#include<bits/stdc++.h>
using namespace std;

struct CumulativeSum {
    int n;
    vector<long long> nums;
    vector<long long> s;
    CumulativeSum(int n) : n(n), s(n + 1, 0) { }
    void add(long long num) {
        nums.push_back(num);
    }
    void build() {
        for (int i = 0; i < n; ++i) s[i+1] = s[i] + nums[i];
    }
    // [l, r), l and r is 0-indexed.
    long long sum(int l, int r) {
        return s[r] - s[l];
    }
};

/*
    verified https://onlinejudge.u-aizu.ac.jp/problems/0516
*/
int main() {
    int n, k;
    vector< long long > ress;
    while (cin >> n >> k) {
        if (n == 0) break;
        CumulativeSum cs(n);
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            cs.add(a);
        }
        cs.build();
        long long res = -1LL<<60;
        for (int i = 0; i <= n - k; ++i) {
            long long val = cs.sum(i, i + k);
            res = max(res, val);
        }
        ress.push_back(res);
    }
    for (long long res : ress) cout << res << endl;
}
