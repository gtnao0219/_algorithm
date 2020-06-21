#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif

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
