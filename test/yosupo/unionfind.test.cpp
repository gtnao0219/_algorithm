#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../data_structure/union_find_tree.cpp"
#undef call_from_test

int main() {
    int N, Q; cin >> N >> Q;
    UnionFindTree uft(N);
    for (int i = 0; i < Q; ++i) {
        int t, u, v; cin >> t >> u >> v;
        if (t == 0) {
            uft.unite(u, v);
        } else {
            cout << (uft.same(u, v) ? 1 : 0) << endl;
        }
    }
}