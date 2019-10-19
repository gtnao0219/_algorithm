#include<bits/stdc++.h>
using namespace std;

// dependency
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
  // Overview

  // Time complexity

  // Initialization
*/
struct Kruskal {
    struct edge{
        int start;
        int to;
        long long cost;
        edge(int start, int to, long long cost) : start(start), to(to), cost(cost) { }
    };
    int v;
    vector< edge > es;
    UnionFindTree uft;
    long long cost_sum = 0;
    Kruskal(int v) : v(v), uft(v) { }
    void add_edge(int start, int to, long long cost) {
        es.emplace_back(start, to, cost);
    }
    void build() {
        sort(es.begin(), es.end(), [](const edge& e1, const edge& e2) {
            return e1.cost < e2.cost;
        });
        for (edge &e : es) {
            if (!uft.same(e.start, e.to)) {
                uft.unite(e.start, e.to);
                cost_sum += e.cost;
            }
        } 
    }
};

/*
    verified https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
*/
int main() {
    int V, E; cin >> V >> E;
    Kruskal kruskal(V);
    for (int i = 0; i < E; ++i) {
        int s, t, d; cin >> s >> t >> d;
        kruskal.add_edge(s, t, d);
    }
    kruskal.build();
    cout << kruskal.cost_sum << endl;
}
