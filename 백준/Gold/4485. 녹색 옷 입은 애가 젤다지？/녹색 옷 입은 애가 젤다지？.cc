#include <iostream>
#include <queue>
using namespace std;

int N, ans;
int board[125][125];
int visited[125][125];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void init() {
	ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			visited[i][j] = 1e8;
		}
	}
}

void solve() {
	priority_queue < pair<int, pair<int, int>>> pq;
	pq.push({ -board[0][0], {0, 0} });
	visited[0][0] = board[0][0];
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				int n_cost = cost + board[nx][ny];
				if (n_cost < visited[nx][ny]) {
					visited[nx][ny] = n_cost;
					pq.push({ -n_cost,{nx, ny} });
				}
			}
		}
	}
	ans = visited[N - 1][N - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int tc = 1; ;tc++) {
		cin >> N;
		if (N == 0) break;
		init();
		solve();
		cout << "Problem " << tc << ": " << ans << '\n';
	}
}