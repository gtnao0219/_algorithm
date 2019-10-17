#include<bits/stdc++.h>
using namespace std;

struct Imos {
    int n;
    vector<long long> nums;
    Imos(int n) : n(n), nums(n + 1, 0) { }
    // [l, r), l and r is 0-indexed.
    void add(int left, int right, long long num) {
        nums[left] += num;
        nums[right] -= num;
    }
    void build() {
        for (int i = 0; i < n; ++i) nums[i + 1] += nums[i];
    }
};

/*
    verified https://onlinejudge.u-aizu.ac.jp/problems/DSL_5_A
*/
int main() {
    int n, t; cin >> n >> t;
    Imos imos(t);
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        imos.add(l, r, 1);
    }
    imos.build();
    cout << *max_element(imos.nums.begin(), imos.nums.end()) << endl;
}
