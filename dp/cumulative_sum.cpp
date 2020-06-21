#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif

template<typename T>
struct CumulativeSum {
    vector<T> s;
    CumulativeSum(const vector<T> &nums) {
        int n = nums.size();
        s.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
    }
    // [l, r), l and r is 0-indexed.
    T sum(int l, int r) {
        return s[r] - s[l];
    }
};
