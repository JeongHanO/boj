#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int second = 0;
int map[20][20];
int visited[20][20];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int shark_size = 2;
int eaten_cnt = 0;
pair<int, int> pos;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) { // 상어의 처음 위치 저장
                pos = { i, j };
                map[i][j] = 0;
            }
        }
    }
}

void init_visited() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = -1;
        }
    }
}

pair<int, pair<int, int>> bfs() {
    init_visited();

    vector<pair<int, pair<int, int>>> fishes;

    queue<pair<int, int>> q;
    q.push({ pos.first, pos.second });
    visited[pos.first][pos.second] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] < 0) { //범위 내부 & 방문X
                if (map[nx][ny] > shark_size) continue; // 상어보다 큰 물고기가 있으면 못 지나감
                visited[nx][ny] = visited[x][y] + 1;
                if (map[nx][ny] > 0 && map[nx][ny] < shark_size) { // 상어보다 작은 물고기는 먹을 수 있음
                    fishes.push_back({ visited[nx][ny],{nx,ny} });
                }
                q.push({ nx,ny });
            }
        }
        

    }

    if (fishes.empty()) { // 먹을 수 있는 생선이 없으면
        return { -1, {-1, -1} };
    }

    sort(fishes.begin(), fishes.end(), [](const pair<int, pair<int, int>>& x, const pair<int, pair<int, int>>& y) {
        if (x.first != y.first) {
            return x.first < y.first;
        }
        else if (x.second.first != y.second.first) {
            return x.second.first < y.second.first;
        }
        else {
            return x.second.second < y.second.second;
        }
    });

    return fishes[0];
}

void solve() {
    while (1) {
        pair<int, pair<int, int>> fish = bfs(); // 거리가 가깝고 1,1에 가까운 물고기
        if (fish.first == -1) { // 먹을 수 있는 생선이 없으면 답 출력 & 종료
            cout << second;
            return;
        }
        second += fish.first;
        eaten_cnt += 1;
        if (eaten_cnt == shark_size) { // 상어 사이즈만큼 먹었으면 상어 사이즈 +1
            shark_size += 1;
            eaten_cnt = 0;
        }
        // 먹은 물고기 제거 & 상어 이동
        map[fish.second.first][fish.second.second] = 0;
        pos.first = fish.second.first;
        pos.second = fish.second.second;
    }
}

int main() {
    input();
    solve();
    return 0;
}
