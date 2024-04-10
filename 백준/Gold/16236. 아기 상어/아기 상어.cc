#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int board[21][21];
int shark_size = 2;
int shark_eaten = 0;
int ans = 0;
pair<int, int> shark; // 상어 위치

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a; cin >> a;
            board[i][j] = a;
            if(a == 9) shark = {i, j};
        }
    }
}

bool bfs(){
    int dist = 1;
    int tmp_board[21][21] = {{0}};
    bool visited[21][21] = {{false}};
    bool found;
    queue<pair<int, int>> q;
    q.push({shark.first, shark.second});
    visited[shark.first][shark.second] = true;
    while(!q.empty()){
        found = false; // 먹을 물고기를 찾음
        int q_size = q.size();
        for(int x = 0; x < q_size; x++){ // 탐색한 거리+1인 칸 탐색
            pair<int, int> loc = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){ // 주변 칸 확인
                int nx = loc.first + dx[i];
                int ny = loc.second + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] > shark_size || visited[nx][ny]) continue; // 범위 이탈 or 큰 물고기 칸 or 이미 방문
                visited[nx][ny] = true;
                if(board[nx][ny] != 0 && board[nx][ny] < shark_size){ // 먹을 생선이 있음
                    tmp_board[nx][ny] = dist;
                    found = true;
                }
                q.push({nx, ny});
            }
        }
        if(found) break; // 거리가 가까운 물고기를 찾았으니 탐색 종료
        dist += 1;
    }

    if(!found) return false; // 더 이상 먹을 수 있는 물고기 없음
    
    int sec = 1000000;
    pair<int, int> tmp_loc;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(tmp_board[i][j] == 0) continue;
            if(tmp_board[i][j] < sec){
                tmp_loc = {i, j};
                sec = tmp_board[i][j];
            }
        }
    }

    board[tmp_loc.first][tmp_loc.second] = 0; // 먹은 물고기 삭제
    board[shark.first][shark.second] = 0;
    shark.first = tmp_loc.first; // 상어 이동
    shark.second = tmp_loc.second;
    board[shark.first][shark.second] = 9;
    shark_eaten += 1;
    if(shark_eaten == shark_size){
        shark_eaten = 0;
        shark_size++;
    }
    ans += dist;
    
    return true;
}

void solve(){
    int round = 0;
    while(true){
        if(!bfs()){
            break;
        }
        // cout << "round: " << round++ << endl;
        // print();
    }
}

int main(){
    input();
    solve();
    cout << ans << endl;
}