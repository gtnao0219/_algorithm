#include<bits/stdc++.h>
using namespace std;

struct SieveOfEstosthenes {
    int n;
    vector<bool> is_prime;
    vector<int> prime;
    SieveOfEstosthenes(int n) : n(n), is_prime(n, true) {
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= n; ++i) {
            if (is_prime[i]) {
                prime.push_back(i);
                for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
            }
        }
    }
};

/*
    verified https://onlinejudge.u-aizu.ac.jp/problems/0009
*/
int main() {
    int n;
    while (cin >> n) {
        SieveOfEstosthenes era(n);
        cout << era.prime.size() << endl;
    }
}
