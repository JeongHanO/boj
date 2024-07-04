#include <iostream>
using namespace std;

int n;
int board[101][101];
long dp[101][101];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) break;
			if (board[i][j] + i < n) {
				dp[i + board[i][j]][j] += dp[i][j];
			}
			if (board[i][j] + j < n) {
				dp[i][j + board[i][j]] += dp[i][j];
			}
		}
	}

	cout << dp[n-1][n-1];
}