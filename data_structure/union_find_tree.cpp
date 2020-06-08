#include<bits/stdc++.h>
using namespace std;

struct UnionFindTree {
    UnionFindTree(int n) : parent(n, -1), rank(n, 0) { }
    int root(int x) {
        if (parent[x] == -1) return x;
        else return parent[x] = root(parent[x]);
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        parent[y] = x;
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
private:
    vector<int> parent, rank;
};

/*
    verified
    https://atcoder.jp/contests/atc001/tasks/unionfind_a
*/
int main() {
    int n, q; cin >> n >> q;
    UnionFindTree uft(n);
    for (int i = 0; i < q; ++i) {
        int com, x, y; cin >> com >> x >> y;
        if (com == 0) uft.unite(x, y);
        else cout << (uft.same(x, y) ? "Yes" : "No") << endl;
    }
}
