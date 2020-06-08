#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct BIT {
    BIT(int n) : n(n), bit(n + 1, 0) { }
    // i is 0-indexed.
    void add(int i, T x) {
        for (++i; i <= n + 1; i += i & -i) bit[i] += x;
    }
    // [0, i), i is 0-indexed.
    T sum(int i) {
        T res = 0;
        for (; i > 0; i -= i & -i) res += bit[i];
        return res;
    }
    // [l, r), l and r is 0-indexed.
    T sum(int l, int r) {
        return sum(r) - sum(l);
    }
private:
    int n;
    vector<T> bit;
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
