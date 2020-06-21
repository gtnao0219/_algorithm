#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../dp/largest_rectangle.cpp"
#undef call_from_test

int main() {
    int N;
    cin >> N;
    vector<long long> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i];
    cout << largest_rectangle(h) << endl;
}
