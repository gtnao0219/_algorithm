#include<bits/stdc++.h>
using namespace std;

// dependency
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    long long g = gcd(a, b);
    return a / g * b;
}

/*
    verified https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_B
*/
int main() {
    long long a, b;
    while (cin >> a >> b) {
        long long g = gcd(a, b);
        long long l = lcm(a, b);
        cout << g << " " << l << endl;
    }
}
