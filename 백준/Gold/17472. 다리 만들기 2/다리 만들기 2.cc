#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, cnt, ans;
int board[10][10];
bool selected[7];
vector<int> v[7]; // 연결된 섬
priority_queue < pair<int, pair<int, int>>> pq; // 가중치, {연결된 섬 a,b}

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void init() {
	ans = 0;
	for (int i = 1; i <= 6; i++) {
		selected[i] = false;
		v[i].clear();
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = 0;
		}
	}
	while (!pq.empty()) {
		pq.pop();
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
}

void make_node() {
	bool visited[10][10] = { false };
	queue<pair<int, int>> q;
	// 각 섬에 번호 메기기
	int idx = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1 && !visited[i][j] && board[i][j] == 1) {
				q.push({ i, j });
				visited[i][j] = true;
				board[i][j] = idx;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny] || board[nx][ny] == 0) continue;
						visited[nx][ny] = true;
						q.push({ nx, ny });
						board[nx][ny] = idx;
					}
				}
				cnt = idx;
				idx++;
			}
		}
	}
}

void make_graph() {
	bool visited[7][7] = { false }; // [i][j] = i섬과 j섬에 대한 간선 생성 완료
	// 각 열에 대해 탐색
	for (int i = 0; i < N; i++) {
		pair<int, int> island = { 0, 0 }; // 섬 번호, 섬의 끝
		for (int j = 0; j < M; j++) {
			// 섬을 만난적 없을 때, 섬을 만나면 번호 기록 + 섬의 끝 기록
			// 저장된 섬 정보가 있을 때, 새로운 섬을 만나면 간선 기록(v + pq에 삽입)
			if (board[i][j] > 0) { // 섬이 있는 칸
				if (island.first == 0) { // 아직 만난 섬 없음
					island = { board[i][j], j }; // 섬 번호, 열 기록
				}
				else { // 만난 섬 있음
					if (board[i][j] == island.first) {
						island.second = j; // 마지막 위치 갱신
						continue;
					}; // 같은 섬
					//if (visited[board[i][j]][island.first]) {
					//	island = { board[i][j], j };
					//	continue;
					//} // 이미 기록된 섬
					int dist = j - island.second - 1;
					if (dist == 1) {
						island = { board[i][j], j };
						continue;
					}
					pq.push({ -dist,{board[i][j], island.first} }); // 최소 수로 하기 위해서 음수 입력
					visited[board[i][j]][island.first] = true;
					visited[island.first][board[i][j]] = true;
					island = { board[i][j], j };
				}
			}
		}
	}
	// 각 행에 대해 탐색
	for (int j = 0; j < M; j++) {
		if (j == 4) {
			int d = 0;
		}
		pair<int, int> island = { 0, 0 }; // 섬 번호, 섬의 끝
		for (int i = 0; i < N; i++) {
			// 섬을 만난적 없을 때, 섬을 만나면 번호 기록 + 섬의 끝 기록
			// 저장된 섬 정보가 있을 때, 새로운 섬을 만나면 간선 기록(v + pq에 삽입)
			if (board[i][j] > 0) { // 섬이 있는 칸
				if (island.first == 0) { // 아직 만난 섬 없음
					island = { board[i][j], i }; // 섬 번호, 열 기록
				}
				else { // 만난 섬 있음
					if (board[i][j] == island.first) {
						island.second = i; // 마지막 위치 갱신
						continue;
					}; // 같은 섬
					//if (visited[board[i][j]][island.first]) { 
					//	island = { board[i][j], i };
					//	continue; 
					//} // 이미 기록된 섬
					int dist = i - island.second - 1;
					if (dist == 1) { 
						island = { board[i][j], i };
						continue; 
					}
					pq.push({ -dist,{board[i][j], island.first} });
					visited[board[i][j]][island.first] = true;
					visited[island.first][board[i][j]] = true;
					island = { board[i][j], i };
				}
			}
		}
	}
}

bool bfs(int start, int dest) {
	bool visited[7] = { false };
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			if (!visited[v[now][i]]) {
				if (v[now][i] == dest) {
					return true;
				}
				visited[v[now][i]] = true;
				q.push(v[now][i]);
			}
		}
	}
	return false;
}

void check() {
	bool visited[7] = { false };
	queue<int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			if (!visited[v[now][i]]) {
				visited[v[now][i]] = true;
				q.push(v[now][i]);
			}
		}
	}
	for (int i = 1; i <= cnt; i++) {
		if (!visited[i]) {
			ans = -1;
			return;
		}
	}
}

void make_bridge() {
	bool selected[7] = { false };
	// 가장 짧은 간선을 뽑아쓰며 다리를 잇고 모든 섬이 연결됐는지 확인
	while (!pq.empty()) {
		int dist = -pq.top().first; // 음수로 넣었으니 뽑을 때 양수로 바꿔주기
		int fir = pq.top().second.first;
		int sec = pq.top().second.second;
		pq.pop();
		if (!bfs(fir, sec)) { // 섬끼리 연결이 안됐으면
			selected[fir] = true;
			selected[sec] = true;
			v[fir].push_back(sec);
			v[sec].push_back(fir);
			ans += dist;
		}
	}

	check();
}

void solve() {
	make_node();
	make_graph();
	make_bridge();
}

int main() {
	init();
	input();
	solve();
	cout << ans << endl;
}


/*
모든 섬을 연결하는 다리 길이의 최소 비용
모든 섬에 대해 연결을 시도하면 될지도?

섬끼리 연결되는지는 어떻게 알지?
가로 / 세로로만 연결 가능.
-> 가로로 같은 칸이 있거나 세로로 같은 칸이 있어야함.

모든 섬이 연결됐는지는 어떻게 확인? -> bfs로?

우선 각 섬에대해 연결할 수 있는 섬이 있는지 확인
ex) a섬의 위치에서 가로로 연결할 수 있는 섬, 세로로 연결할 수 있는 섬 확인

케이스가 적어서 완전 탐색해도 되긴 함

가장 작은 비용이니까 그래프 형식으로 해야할듯
각 섬을 노드로 표현, 노드에서 다른 노드로 이을 수 있는 경우와 가중치를 계산.

priority_queue를 이용해서 가장 작은 간선부터 고르기.

각 섬에 대해서 한 칸씩 이동하면서 

연결 못하면 -1 출력

1. 각 섬을 노드로 표현. bfs돌리면서 영역 확인.
2. 각 섬에서 직선상 위치한 섬이 있는지 확인. 있다면 거리(가중치) 계산.
	2-1. 굳이 섬에서 출발하지 않고, 각 행과 열을 확인하면서 숫자에 따른 거리로 계산하면 될듯.
	ex) 4행을 탐색. b섬의 끝인 4와 d섬의 시작인 7을 비교. 7-4-1 값을 거리로 생각
3. 계산된 가중치를 그래프 형식으로 기록
4. 가중치를 기준으로 pq에 모든 간선을 넣고 다리 선택.
	4-1. selected 배열을 만들어 선택되지 않은 곳이 있는지 확인. (간선 개수가 적어서 가능)
*/