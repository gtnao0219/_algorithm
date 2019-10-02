#include<bits/stdc++.h>
using namespace std;

struct UnionFindTree {
    vector<int> par, rank;
    UnionFindTree(int n) : par(n , -1), rank(n, 0) { }
    int find(int x) {
        if (par[x] == -1) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

/*
    verified
    https://atcoder.jp/contests/abc120/tasks/abc120_d
*/
int main() {
    int n, q; cin >> n >> q;
    UnionFindTree union_find_tree(n);
    for (int i = 0; i < q; ++i) {
        int com, x, y; cin >> com >> x >> y;
        if (com == 0) union_find_tree.unite(x, y);
        else cout << union_find_tree.same(x, y) << endl;
    }
}
