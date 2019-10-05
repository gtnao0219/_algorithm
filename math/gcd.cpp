#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

/*
    verified https://atcoder.jp/contests/abc109/tasks/abc109_c
*/
int main() {
    int n, x; cin >> n >> x;
    vector<int> xs(n + 1);
    for (int i = 0; i < n; ++i) cin >> xs[i];
    xs[n] = x;
    int _min = *min_element(xs.begin(), xs.end());
    for (int i = 0; i < n + 1; ++i) xs[i] -= _min;
    int res = xs[0];
    for (int i = 1; i < n + 1; ++i) res = gcd(res, xs[i]);
    cout << res << endl;
}
