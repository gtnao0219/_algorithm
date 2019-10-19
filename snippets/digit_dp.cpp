#include<bits/stdc++.h>
using namespace std;

long long solve(string s) {
    int n = s.size();
	vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		int D = s[i] - '0';
		for (int j = 0; j < 2; ++j) {
			for (int d = 0; d <= (j ? 9 : D); ++d) {
				dp[i + 1][j || ( d < D )] += dp[i][j];
			}
		}	
	}
	return dp[n][0] + dp[n][1];
}

int main() {
    string s; cin >> s;
    cout << solve(s) << endl;
}
