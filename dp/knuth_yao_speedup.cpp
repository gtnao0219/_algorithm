#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif

template<typename T, typename F>
T knuthYaoSpeedup(int n, F costF) {
    vector<vector<T>> dp(n, vector<T>(n, numeric_limits<T>::max()));
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = T(0);
        a[i][i] = i;
    }
    for (int width = 1; width < n; ++width) {
        for (int i = 0; i + width < n; ++i) {
            int j = i + width;
            for (int k = a[i][j - 1]; k <= a[i + 1][j] && k + 1 <= j; ++k) {
                T res = dp[i][k] + dp[k + 1][j] + costF(i, k, j);
                if (res < dp[i][j]) {
                    dp[i][j] = res;
                    a[i][j] = k;
                }
            }
        }
    }
    return dp[0][n - 1];
};
