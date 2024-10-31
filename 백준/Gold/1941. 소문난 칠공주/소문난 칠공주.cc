#include <iostream>
#include <string>
#include <queue>
using namespace std;

int ans = 0;
char board[5][5];
bool selected[5][5];

bool checkFour() {
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (selected[i][j] && board[i][j] == 'S') {
				cnt++;
			}
		}
	}
	if (cnt >= 4) return true;
	return false;
}

bool checkNear() {
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	queue<pair<int, int>> q;
	for (int i = 0; i < 5; i++) {
		bool flag = false;
		for (int j = 0; j < 5; j++) {
			if (selected[i][j]) {
				q.push({ i,j });
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	int cnt = 1;
	bool visited[5][5];
	
	for (int i = 0; i < 25; i++) {
		visited[i / 5][i % 5] = false;
	}

	visited[q.front().first][q.front().second] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
			if (!selected[nx][ny])continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push({ nx, ny });
			cnt++;
		}
	}

	if (cnt == 7) return true;
	return false;
}

void select(int idx, int depth) {
	if (depth == 7) {
		// 4명 이상 확인, 인접한지 확인
		if (checkFour() && checkNear()) {
			ans++;
			checkNear();
		}
		return;
	}
	for (int i = idx + 1; i < 25; i++) {
		selected[i / 5][i % 5] = true;
		select(i, depth+1);
		selected[i / 5][i % 5] = false;
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		string s; cin >> s;
		for (int j = 0; j < 5; j++) {
			if (s[j] == 'Y') board[i][j] = 'Y';
			else board[i][j] = 'S';
		}
	}

	for (int i = 0; i < 25; i++) {
		selected[i / 5][i % 5] = true;
		select(i, 1);
		selected[i / 5][i % 5] = false;
	}

	cout << ans << endl;
}