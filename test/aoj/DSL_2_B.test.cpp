#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../data_structure/binary_indexed_tree.cpp"
#undef call_from_test

int main() {
    int n, q; cin >> n >> q;
    BIT<int> bit(n);
    for (int i = 0; i < q; ++i) {
        int com, x, y; cin >> com >> x >> y;
        if (com == 0) bit.add(--x, y);
        else cout << bit.sum(--x, y) << endl;
    }
}
