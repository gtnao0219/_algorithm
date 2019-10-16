#include<bits/stdc++.h>
using namespace std;

/*
  // Overview

  // Time complexity

  // Initialization
*/
template<typename T, bool directed>
struct FordFulkerson {
    struct edge{
        int to, rev;
        T cap;
        edge(int to, int rev, T cap) : to(to), rev(rev), cap(cap) { }
    };
    int n;
    int s;
    int t;
    vector< vector< edge > > g;
    vector< bool > used;
    FordFulkerson(int n, int s, int t) : n(n), s(s), t(t), g(n) { }
    void add_edge(int from, int to, T cap) {
        g[from].emplace_back(to, g[to].size(), cap);
        g[to].emplace_back(from, g[from].size() - 1, directed ? 0 : cap);
    }
    T dfs(int v, T f) {
        if (v == t) return f;
        used[v] = true;
        for (edge &e : g[v]) {
            if (!used[e.to] && e.cap > 0) {
                int d = dfs(e.to, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    T solve() {
        T res = 0;
        while (true) {
            used.assign(n, false);
            T f = dfs(s, numeric_limits<T>::max()/2);
            if (f == 0) return res;
            res += f;
        }
    }
};

/*
    verified http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp
*/
int main() {
    int V, E; cin >> V >> E;
    FordFulkerson<int, true> ff(V, 0, V - 1);
    for (int i = 0; i < E; ++i) {
        int u, v, c; cin >> u >> v >> c;
        ff.add_edge(u, v, c);
    }
    cout << ff.solve() << endl;
}
