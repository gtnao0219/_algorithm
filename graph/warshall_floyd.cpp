#include<bits/stdc++.h>
using namespace std;

struct WarshallFloyd {
    typedef vector< vector< long long > > Matrix;
    const long long INF = 1LL<<60;
    int n;
    Matrix g;
    WarshallFloyd(int n) : n(n), g(n, vector< long long >(n, INF)) {
        for (int i = 0; i < n; ++i) g[i][i] = 0;
    }
    void add_edge(int u, int v, long long c) {
        g[u][v] = c;
    }
    void build() {
        for (int k = 0; k < g.size(); ++k) {
            for (int i = 0; i < g.size(); ++i) {
                for (int j = 0; j < g.size(); ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }
    bool is_negative_cycle() {
        for (int i = 0; i < n; ++i) if (g[i][i] < 0) return true;
        return false;
    }
    long long path(int s, int t) {
        if (g[s][t] < INF / 2) return g[s][t];
        return INF;
    }
};

/*
    verified http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp
*/
int main() {
    int v, e; cin >> v >> e;
    WarshallFloyd wf(v);
    for (int i = 0; i < e; ++i) {
        int s, t, d; cin >> s >> t >> d;
        wf.add_edge(s, t, d);
    }
    wf.build();
    if (wf.is_negative_cycle()) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            if (j != 0) cout << " ";
            long long path = wf.path(i, j);
            if (path == wf.INF) cout << "INF";
            else cout << path;
        }
        cout << endl;
    }
}