#include<bits/stdc++.h>
using namespace std;

/*
  // Overview
  グラフの全点間最短路を求める。
  負辺があっても動作。負閉路検出可能。

  // Time complexity
  O(n ^ 3) (n: 頂点の数)

  // Initialization
  WarshallFloyd wf = WarshallFloyd(n); (n: 頂点の数)
  wf.add_edge(u, v, c); (u: start, v: to, c: コスト) (無向グラフの場合は両辺に張る)
  wf.build();
*/
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
                    if(g[i][k] == INF || g[k][j] == INF) continue;
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }
    // Time complexity
    // O(n) (n: 頂点数)
    bool has_negative_cycle() {
        for (int i = 0; i < n; ++i) if (g[i][i] < 0) return true;
        return false;
    }
    long long shortest_path_value(int s, int t) {
        return g[s][t];
    }
    bool is_unreachable(int s, int t) {
        return g[s][t] == INF;
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
    if (wf.has_negative_cycle()) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            if (j != 0) cout << " ";
            if (wf.is_unreachable(i, j)) cout << "INF";
            else cout << wf.shortest_path_value(i, j);
        }
        cout << endl;
    }
}

/*
    verified https://atcoder.jp/contests/abc073/tasks/abc073_d
*/
int main() {
    int n, m, r; cin >> n >> m >> r;
    vector<int> rs(r);
    for (int i = 0; i < r; ++i) {
        cin >> rs[i];
        --rs[i];
    }
    WarshallFloyd wf(n);
    for (int i = 0; i < m; ++i) {
        int s, t, d; cin >> s >> t >> d;
        --s, --t;
        wf.add_edge(s, t, d);
        wf.add_edge(t, s, d);
    }
    wf.build();
    sort(rs.begin(), rs.end());
    long long res = 1LL<<60;
    do {
        long long sum = 0;
        for (int i = 1; i < r; ++i) {
            sum += wf.shortest_path_value(rs[i - 1], rs[i]);
        }
        res = min(res, sum);
    } while (next_permutation(rs.begin(), rs.end()));
    cout << res << endl;
}
