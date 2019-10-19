#include<bits/stdc++.h>
using namespace std;

/*
  // Overview

  // Time complexity

  // Initialization
*/
struct Dijkstra {
    struct edge{
        int to;
        long long cost;
        edge(int to, long long cost) : to(to), cost(cost) { }
    };
    typedef pair< long long, int > P;
    const long long INF = 1LL<<60;
    int v;
    int s;
    vector< vector < edge > > g;
    vector< long long > dist;
    priority_queue< P, vector< P >, greater< P > > que;
    Dijkstra(int v, int s) : v(v), s(s), g(v), dist(v, INF) {
        dist[s] = 0;
        que.push(P(0, s));
    }
    void add_edge(int start, int to, long long cost) {
        g[start].emplace_back(to, cost);
    }
    void build() {
        while (!que.empty()) {
            P p = que.top(); que.pop();
            int current = p.second;
            if (dist[current] < p.first) continue;
            for (edge& e : g[current]) {
                if (dist[e.to] > dist[current] + e.cost) {
                    dist[e.to] = dist[current] + e.cost;
                    que.push(P(dist[e.to], e.to));
                }
            }
        }
    }
    long long shortest_path_value(int t) {
        return dist[t];
    }
};

/*
    verified https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
*/
int main() {
    int V, E, r; cin >> V >> E >> r;
    Dijkstra dijkstra(V, r);
    for (int i = 0; i < E; ++i) {
        int s, t, d; cin >> s >> t >> d;
        dijkstra.add_edge(s, t, d);
    }
    dijkstra.build();
    for (int i = 0; i < V; ++i) {
        long long val = dijkstra.shortest_path_value(i);
        if (val == dijkstra.INF) cout << "INF" << endl;
        else cout << val << endl;
    }
}
