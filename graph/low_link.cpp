#include<bits/stdc++.h>
using namespace std;

struct LowLink {
    struct Edge {
        int to;
        Edge(int to) : to(to) { }
    };
    vector<vector<Edge>> graph;
    int v;
    vector<int> used, order, low_link, articulation_points;
    vector<pair<int, int>> bridges;
    LowLink(int v) : v(v), graph(v),  used(v, 0), order(v, 0), low_link(v, 0) {}
    void add_edge(int start, int to) {
        graph[start].emplace_back(to);
        graph[to].emplace_back(start);
    }
    void build() {
        int current_order = 0;
        for (int i = 0; i < v; ++i) {
            if (!used[i]) current_order = dfs(i, current_order, -1);
        }
    }
    int dfs(int id, int current_order, int parent) {
        used[id] = true;
        order[id] = current_order++;
        low_link[id] = order[id];
        bool is_articulation_points = false;
        int child_count = 0;
        for (Edge& e : graph[id]) {
            if (!used[e.to]) {
                ++child_count;
                current_order = dfs(e.to, current_order, id);
                low_link[id] = min(low_link[id], low_link[e.to]);
                if (parent != -1 && order[id] <= low_link[e.to]) is_articulation_points = true;
                if (order[id] < low_link[e.to]) bridges.emplace_back(id, e.to);
            } else {
                if (e.to != parent) {
                    low_link[id] = min(low_link[id], order[e.to]);
                }
            }
        }
        if (parent == -1 && child_count >= 2) is_articulation_points = true;
        if (is_articulation_points) articulation_points.push_back(id);
        return current_order;
    }
};

/*
    verified http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B&lang=jp
    verified http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=jp
*/
int main() {
    int V, E; cin >> V >> E;
    LowLink low_link(V);
    for (int i = 0; i < E; ++i) {
        int s, t; cin >> s >> t;
        low_link.add_edge(s, t);
    }
    low_link.build();

    // birdges
    // for (auto& bridge : low_link.bridges) if (bridge.first > bridge.second) swap(bridge.first, bridge.second);
    // std::sort(low_link.bridges.begin(), low_link.bridges.end());
    // for (auto bridge : low_link.bridges) {
    //     cout << bridge.first << " " << bridge.second << endl;
    // }

    // articulation_points
    std::sort(low_link.articulation_points.begin(), low_link.articulation_points.end());
    for (auto articulation_point : low_link.articulation_points) {
        cout << articulation_point << endl;
    }
}
