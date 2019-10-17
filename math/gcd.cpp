#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

/*
    verified https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_B
*/
int main() {
    int x, y; cin >> x >> y;
    cout << gcd(x, y) << endl;
}
