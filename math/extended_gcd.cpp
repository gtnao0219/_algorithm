#include<bits/stdc++.h>
using namespace std;

long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    int d = a;
    if (b != 0) {
        d = extended_gcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}

/*
    verified https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E
*/
int main() {
    long long a, b, x, y; cin >> a >> b;
    extended_gcd(a, b, x, y);
    cout << x << " " << y << endl;
}
