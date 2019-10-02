#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    BIT(int _n) : n(_n), bit(_n + 1) { }
    // [0, i], i is 0-indexed.
    T sum(int i) {
        T s = 0;
        for (i++; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
    // [l, r), l and r is 0-indexed.
    T sum(int l, int r) {
        return sum(r - 1) - sum(l - 1);
    }
    void add(int i, T x) {
        for (i++; i <= n; i += i & -i) bit[i] += x;
    }
};

/*
    verified http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp
*/
int main() {
    int n, q; cin >> n >> q;
    BIT<int> bit(n);
    for (int i = 0; i < q; ++i) {
        int com, x, y; cin >> com >> x >> y;
        if (com == 0) bit.add(--x, y);
        else cout << bit.sum(--x, y) << endl;
    }
}
