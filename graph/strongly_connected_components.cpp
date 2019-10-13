#include<bits/stdc++.h>
using namespace std;

/*
  // Time complexity
  O(v + e) (v: 頂点の数, e: 辺の数)

  // Initialization
  StronglyConnectedComponents scc = StronglyConnectedComponents(n); (n: 頂点の数)
  scc.add_edge(u, v); (u: start, v: to)
  scc.build();
*/

struct StronglyConnectedComponents {
    int n;
    vector< vector< int > > g;
    vector< vector< int > > rg;
    vector< bool > used;
    vector< int > order, comp;
    StronglyConnectedComponents(int n) : n(n), g(n), rg(n), used(n, false), comp(n, -1) { }
    void add_edge(int u, int v) {
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    void build() {
        for (int i = 0; i < n; ++i) {
            if(!used[i]) dfs(i);
        }
        int cnt = 0;
        reverse(order.begin(), order.end());
        for(int i : order) {
            if(comp[i] == -1) rdfs(i, cnt++);
        }
    }
    int operator[](int k) {
        return comp[k];
    }
    void dfs(int idx) {
        used[idx] = true;
        for (int to : g[idx]) {
            if (!used[to]) dfs(to);
        }
        order.push_back(idx);
    }
    void rdfs(int idx, int cnt) {
        comp[idx] = cnt;
        for (int to : rg[idx]) {
            if(comp[to] == -1) rdfs(to, cnt);
        }
    }
};

/*
    verified http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C&lang=jp
*/
int main() {
    int v, e; cin >> v >> e;
    StronglyConnectedComponents scc = StronglyConnectedComponents(v);
    for (int i = 0; i < e; ++i) {
        int s, t; cin >> s >> t;
        scc.add_edge(s, t);
    }
    scc.build();
    int q; cin >> q;
    vector< int > us(q), vs(q);
    for (int i = 0; i < q; ++i) {
        cin >> us[i] >> vs[i];
    }
    for (int i = 0; i < q; ++i) {
        cout << (scc[us[i]] == scc[vs[i]] ? 1 : 0) << endl;
    }
}
