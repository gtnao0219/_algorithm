#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_B"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/gcd.cpp"
#undef call_from_test

int main() {
    int x, y; cin >> x >> y;
    cout << gcd(x, y) << endl;
}