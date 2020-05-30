#include<bits/stdc++.h>
using namespace std;

// graph type definitions
struct Edge {
    int to;
    Edge(int to) : to(to) { }
};
using Graph = vector<vector<Edge>>;

int main() {
    // prepare sample data
    int n = 7;
    Graph g(n);
    g[0].emplace_back(1);
    g[0].emplace_back(2);
    g[1].emplace_back(3);
    g[1].emplace_back(4);
    g[2].emplace_back(5);
    g[2].emplace_back(6);

    // これらの変数は全てのDFSで必要ではない
    // seen: 遷移可能かの判定に用いる
    // order: 確認用途
    vector<bool> seen(n);
    vector<int> order;
    // 必須
    queue<int> que;

    // 最初の処理(ループ内の処理と同様)
    seen[0] = true;
    order.push_back(0);
    // 必須
    que.push(0);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto e : g[v]) {
            int next_v = e.to;
            if (seen[next_v]) continue;

            // 処理
            seen[next_v] = true;
            order.push_back(next_v);
            // 必須
            que.push(next_v);
        }
    }
    
    // debug
    for (auto v : order) cout << v << " ";
    cout << endl;
}