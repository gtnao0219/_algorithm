#include<bits/stdc++.h>
using namespace std;

// [l, r), l and r is 0-indexed.
template<typename T>
using Interval = tuple<int, int, T>;
template<typename T>
struct Imos {
    int n;
    vector<T> s;
    Imos(int n, const vector<Interval<T>> &intervals) : n(n) {
        s.resize(n + 1, 0);
        for (auto interval : intervals) {
            T v = std::get<2>(interval);
            s[std::get<0>(interval)] += v;
            s[std::get<1>(interval)] -= v;
        }
        for (int i = 0; i < n; ++i) s[i + 1] += s[i];
    }
    int size() {
        return n;
    }
    T get(int i) {
        return s[i];
    }
};

/*
    verified https://onlinejudge.u-aizu.ac.jp/problems/DSL_5_A
*/
int main() {
    int n, t; cin >> n >> t;
    vector<Interval<long long>> intervals(n);
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        intervals[i] = make_tuple(l, r, 1);
    }
    Imos<long long> imos(t, intervals);
    long long res = numeric_limits<long long>::min();
    for (int i = 0; i < imos.size(); ++i) {
        res = max(res, imos.get(i));
    }
    cout << res << endl;
}
