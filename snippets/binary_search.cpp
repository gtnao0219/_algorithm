#include<bits/stdc++.h>
using namespace std;

// TFunc: function<bool(long long idx)>
template <typename TFunc>
long long binary_search(long long ng, long long ok, TFunc is_ok) {
    while (abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        
        if (is_ok(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    vector<int> sample = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

    cout << "--more than min--" << endl;
    long long ng = -1;
    long long ok = sample.size();
    auto is_ok = [&](long long idx, int key) {
        if (sample[idx] >= key) return true;
        else return false;
    };
    cout << binary_search(ng, ok, [&](long long idx) { return is_ok(idx, 51); }) << endl;
    cout << binary_search(ng, ok, [&](long long idx) { return is_ok(idx, 1); }) << endl;
    cout << binary_search(ng, ok, [&](long long idx) { return is_ok(idx, 910); }) << endl;
    cout << binary_search(ng, ok, [&](long long idx) { return is_ok(idx, 52); }) << endl;
    cout << binary_search(ng, ok, [&](long long idx) { return is_ok(idx, 0); }) << endl;
    cout << binary_search(ng, ok, [&](long long idx) { return is_ok(idx, 911); }) << endl;

    cout << "--less than max--" << endl;
    long long ng_2 = sample.size();
    long long ok_2 = -1;
    auto is_ok_2 = [&](long long idx, int key) {
        if (sample[idx] <= key) return true;
        else return false;
    };
    cout << binary_search(ng_2, ok_2, [&](long long idx) { return is_ok_2(idx, 51); }) << endl;
    cout << binary_search(ng_2, ok_2, [&](long long idx) { return is_ok_2(idx, 1); }) << endl;
    cout << binary_search(ng_2, ok_2, [&](long long idx) { return is_ok_2(idx, 910); }) << endl;
    cout << binary_search(ng_2, ok_2, [&](long long idx) { return is_ok_2(idx, 52); }) << endl;
    cout << binary_search(ng_2, ok_2, [&](long long idx) { return is_ok_2(idx, 0); }) << endl;
    cout << binary_search(ng_2, ok_2, [&](long long idx) { return is_ok_2(idx, 911); }) << endl;
}