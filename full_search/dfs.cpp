#include<bits/stdc++.h>
using namespace std;

// graph type definitions
struct Edge {
    int to;
    Edge(int to) : to(to) { }
};
using Graph = vector<vector<Edge>>;

// 関数として定義する場合
// 現在の状態と合わせて、参照したい値を全て渡す
void dfs(const Graph &g, vector<bool> &seen, vector<int> &first_order, vector<int> &last_order, int v) {
    // 行きがけ処理
    seen[v] = true;
    first_order.push_back(v);

    // 現在の状態から遷移可能な状態へ
    for (auto e : g[v]) {
        int next_v = e.to;
        if (seen[next_v]) continue;
        dfs(g, seen, first_order, last_order, next_v);
    }

    // 帰りがけ処理
    last_order.push_back(v);
}

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

    // これらの変数は全てのDFSで必要ではない
    // seen: 遷移可能かの判定に用いる
    // first_order, last_order: 確認用途
    vector<bool> seen(n);
    vector<int> first_order;
    vector<int> last_order;

    dfs(g, seen, first_order, last_order, 0);

    // debug
    cout << "first_order: ";
    for (auto v : first_order) cout << v << " ";
    cout << endl;
    cout << "last_order: ";
    for (auto v : last_order) cout << v << " ";
    cout << endl;
}