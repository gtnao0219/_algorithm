#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif

template<typename T>
T largest_rectangle(vector<T> &v) {
    int n = v.size();
    vector<int> L(n, -1);
    vector<int> R(n, n);
    // index, height
    using P = pair<int, T>;
    stack<P> sl;
    stack<P> sr;

    // L
    for (int i = n - 1; i >= 0; --i) {
        // stackに入っているより大きい要素を取り除く
        while (!sl.empty() && sl.top().second > v[i]) {
            // 現在のindexを渡す
            L[sl.top().first] = i;
            sl.pop();
        }
        // stackへ追加
        sl.emplace(i, v[i]);
    }

    // R
    for (int i = 0; i < n; ++i) {
        // stackに入っているより大きい要素を取り除く
        while (!sr.empty() && sr.top().second > v[i]) {
            // 現在のindexを渡す
            R[sr.top().first] = i;
            sr.pop();
        }
        // stackへ追加
        sr.emplace(i, v[i]);
    }

    T res = numeric_limits<T>::min();
    for (int i = 0; i < n; ++i) {
        res = max(res, v[i] * (R[i] - L[i] - 1));
    }
    return res;
}
