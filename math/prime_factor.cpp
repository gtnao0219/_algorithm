#include<bits/stdc++.h>
using namespace std;

map<long long, long long> prime_factor(long long n) {
    map<long long, long long> res;
    for (long long i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}

/*
    verified https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_A
*/
int main() {
    int n; cin >> n;
    cout << n << ":";
    auto pf = prime_factor(n);
    for (auto p : pf) {
        for (int i = 0; i < p.second; ++i) {
            cout << " " << p.first;
        }
    }
    cout << endl;
}