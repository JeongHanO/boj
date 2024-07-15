#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101][100001];
pair<int, int> w[101];
pair<int, int> b[101];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++ ) cin >> w[i].first >> w[i].second >> b[i].first >> b[i].second;
	
	dp[1][w[1].first] = w[1].second;
	dp[1][b[1].first] = max(b[1].second, dp[1][b[1].first]);

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (dp[i - 1][j] != 0) {
				if (j + w[i].first <= k) dp[i][j + w[i].first] = max(dp[i][j + w[i].first], dp[i - 1][j] + w[i].second);
				if (j + b[i].first <= k) dp[i][j + b[i].first] = max(dp[i][j + b[i].first], dp[i - 1][j] + b[i].second);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= k; i++) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans;
}