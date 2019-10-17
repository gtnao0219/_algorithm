#include<bits/stdc++.h>
using namespace std;

vector<long long> divisor(long long n) {
    vector<long long> res;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    // if sort is required
    sort(res.begin(), res.end());
    return res;
}

/*
    verified https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D
*/
int main() {
    int a, b, c; cin >> a >> b >> c;
    auto d = divisor(c);
    int res = 0;
    for (int i = a; i <= b; ++i) {
        if (binary_search(d.begin(), d.end(), i)) ++res;
    }
    cout << res << endl;
}
