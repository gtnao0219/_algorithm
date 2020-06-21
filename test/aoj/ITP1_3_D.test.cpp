#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/divisor.cpp"
#undef call_from_test

int main() {
    int a, b, c; cin >> a >> b >> c;
    auto d = divisor(c);
    sort(d.begin(), d.end());
    int res = 0;
    for (int i = a; i <= b; ++i) {
        if (binary_search(d.begin(), d.end(), i)) ++res;
    }
    cout << res << endl;
}
