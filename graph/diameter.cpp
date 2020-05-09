#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct Diameter {
    struct Edge {
        int to;
        T cost;
        Edge(int to, T cost) : to(to), cost(cost) { }
    };
    typedef pair< T, int > P;
    vector<vector<Edge>> graph;
    int v;
    Diameter(int v) : v(v), graph(v) { }
    T calc() {
        P f = dfs(0, -1);
        P s = dfs(f.second, -1);
        return s.first;
    }
    void add_edge(int start, int to, T cost) {
        graph[start].emplace_back(to, cost);
        graph[to].emplace_back(start, cost);
    }
    P dfs(int id, int parent) {
        P ret = make_pair((T)0, id);
        for (Edge e : graph[id]) {
            if (e.to == parent) continue;
            auto next = dfs(e.to, id);
            next.first += e.cost;
            ret = max(ret, next);
        }
        return ret;
    }
};

/*
    verified https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A
*/
int main() {
    int n; cin >> n;
    Diameter<int> diameter(n);
    for (int i = 0; i < n - 1; ++i) {
        int s, t, w; cin >> s >> t >> w;
        diameter.add_edge(s, t, w);
    }
    cout << diameter.calc() << endl;
}
