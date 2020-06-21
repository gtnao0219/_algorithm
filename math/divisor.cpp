#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif

vector<long long> divisor(long long n) {
    vector<long long> res;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}
