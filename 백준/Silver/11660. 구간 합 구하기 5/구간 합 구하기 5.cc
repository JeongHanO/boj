#include <iostream>
#include <vector>
using namespace std;

int board[1025][1025];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a; cin >> a;
			board[i][j] = board[i - 1][j] + board[i][j - 1] + a - board[i - 1][j - 1];
		}
	}

	int a, b, c, d;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c >>d;
		cout << board[c][d] - board[c][b-1] - board[a-1][d] + board[a-1][b-1] << '\n';
	}

}

/*
x,y ~ x+2,y+2 구해야하면
(x+2, y+2) - (x,y-2) - (x-2,y) + (x,y)
*/