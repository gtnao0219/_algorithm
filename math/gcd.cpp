#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
