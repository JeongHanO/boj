#include <iostream>
using namespace std;

int n;
int x = 1, y = 2; // 파이프의 오른쪽
int board[17][17];
int dp[17][17][3]; // 0: 가로, 1:세로, 2:대각

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			cin >> board[i][j];

	dp[1][2][0] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (dp[i][j][0] > 0) {
				if(board[i][j+1] == 0) dp[i][j + 1][0] += dp[i][j][0];
				if(board[i][j+1] == 0 && board[i + 1][j] == 0 && board[i+1][j + 1] == 0) dp[i + 1][j + 1][2] += dp[i][j][0];
			}
			if (dp[i][j][1] > 0) {
				if (board[i + 1][j] == 0) dp[i+1][j][1] += dp[i][j][1];
				if (board[i][j + 1] == 0 && board[i + 1][j] == 0 && board[i + 1][j + 1] == 0) dp[i + 1][j + 1][2] += dp[i][j][1];
			}
			if (dp[i][j][2] > 0) {
				if (board[i][j + 1] == 0) dp[i][j + 1][0] += dp[i][j][2];
				if (board[i + 1][j] == 0) dp[i + 1][j][1] += dp[i][j][2];
				if (board[i][j + 1] == 0 && board[i + 1][j] == 0 && board[i + 1][j + 1] == 0) dp[i + 1][j + 1][2] += dp[i][j][2];
			}
		}
	}

	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}