#include<bits/stdc++.h>
using namespace std;

bool is_prime(long long n) {
    if (n <= 1) return false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

/*
    verified https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C
*/
int main() {
    int n; cin >> n;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        if (is_prime(tmp)) ++res;
    }
    cout << res << endl;
}
