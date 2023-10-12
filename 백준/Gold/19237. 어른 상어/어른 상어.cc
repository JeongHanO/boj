#include <iostream>
#include <vector>
using namespace std;

int n, m, k, cnt_shark;
int sec = 0;

// 1,2,3,4 -> 위 아래 왼쪽 오른쪽
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1 };
string point[] = {"↑", "↓", "←", "→"};

struct SHARK{
    bool alive;
    int x;
    int y;
    int looking_dir;
    vector<vector<int>> pri_dir; //방향 우선순위 저장
};

struct OCEAN{
    int shark_num; // 없으면 0, 있으면 상어 번호
    int smell_num; // 냄새를 남긴 상어 번호
    int smell_left; // 냄새 사라지기까지 남은 시간
    bool arrive_now; // 새로운 칸에 도착했음을 기록(기존 소유한 칸이면 변경X)
};

OCEAN ocean[20][20];
vector<SHARK> shark(401);

void print_ocean(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ocean[i][j].shark_num << ' ';
        }
        cout << endl;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "[" << ocean[i][j].smell_num << ", " << ocean[i][j].smell_left << "] ";
        }
        cout << endl;
    }
}

void input(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){ // 바다 정보
        for(int j = 0; j < n; j++){
            int a; cin >> a;
            ocean[i][j].shark_num = a;
            ocean[i][j].smell_num = a;
            if(a > 0) { // 상어가 있는 칸이면 냄새 남은 시간 기록, 상어 정보 갱신
                ocean[i][j].smell_left = k;
                shark[a].x = i;
                shark[a].y = j;
            }
        }
    }

    for(int i = 1; i <= m; i++){
        int a; cin >> a;
        shark[i].looking_dir = a;
        shark[i].alive = true;
    }

    for(int i = 1; i <= m; i++){ // 상어 방향 정보
        vector<int> tmp; shark[i].pri_dir.push_back(tmp); // index 조정용
        // cout << "\nSHARK NUM : " << i << endl;
        for(int j = 0; j < 4; j++){
            vector<int> tmp;
            tmp.push_back(0); // index 조정용
            int a, b, c, d; cin >> a >> b >> c >> d;
            tmp.push_back(a); tmp.push_back(b);
            tmp.push_back(c); tmp.push_back(d);
            shark[i].pri_dir.push_back(tmp);
            // cout << point[j] << "일 때 | " << point[a-1] << ' ' << point[b-1]<< ' '  <<point[c-1]<< ' '  <<point[d-1] << endl;
        }
    }
}

// 냄새가 남아있고 상어가 없는 칸(현재 이동한 칸이 아닌 칸)이면 냄새 시간 1 감소. 냄새 시간이 0이면 소유한 상어 정보 삭제.
void dec_smell(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ocean[i][j].arrive_now = false;
            if(ocean[i][j].smell_left > 0 && ocean[i][j].shark_num == 0) ocean[i][j].smell_left -= 1;
            if(ocean[i][j].smell_left == 0) ocean[i][j].smell_num = 0;
        }
    }
}

/*
상어의 현재 위치에서 이동가능한 칸, 자신의 칸 개수 카운트
상어의 이동 우선순위대로 판단하여 벡터에 저장 및 반환
*/
pair<int, pair<int, int>> move_cell(int x, int y, int shark_num){
    pair<int, pair<int, int>> own = make_pair(-1, make_pair(-1, -1));
    int looking_dir = shark[shark_num].looking_dir;
    for(int i = 1; i <= 4; i++){
        int dir = shark[shark_num].pri_dir[looking_dir][i];
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n){ // 격자 범위 확인
            if(ocean[nx][ny].smell_num == 0){ // 우선 순위에 맞는 빈 칸이 나오면 이동
                return make_pair(dir, make_pair(nx, ny));
            // }else if(ocean[nx][ny].shark_num != shark_num && ocean[nx][ny].smell_left == k){ // 번호가 작은 상어와 같은 칸으로 갔을 때
            }else if(ocean[nx][ny].shark_num != shark_num && ocean[nx][ny].arrive_now == true){ // 번호가 작은 상어와 같은 칸으로 갔을 때
                // 기존에 있던 칸으로 되돌아가면 k로 갱신되기 때문에 if문에서 오류가 발생
                // 해결 방법: 1. 새로온 칸과 기존 칸을 구분하는 새로운 방법  2. 
                // cout << "SOMETHING DEAD / num = " << shark_num << " / x, y = " << nx << ' '<< ny << endl;
                return make_pair(dir, make_pair(nx, ny));
            }
             else if(ocean[nx][ny].smell_num == shark_num && own.second.first == -1){ // 자신의 냄새가 있는 칸이고 우선순위로 갈 칸이 없을 때
                own = make_pair(dir, make_pair(nx, ny));
            }
        }
    }
    // cout << "move to own" << endl;
    return own; // 빈 칸이 없으면 자신의 칸 반환
}

/*
상어와 인접한 칸 중 냄새가 없는 칸을 우선적으로 이동. 냄새가 없는 칸이 없으면 자신의 냄새로 이동.
이동 가능한 칸이 여러개 -> 보고있는 방향에 따른 이동 우선순위 적용. (shark[i].pri_dir[looking_dir][j])
이동할 칸을 봤을 때, 냄새가 남음시간이 0이거나 k이면 이동 가능한 칸으로 판단.(k라는 건 동일한 시점에서 이동했다는 뜻)
이동하는 곳이 냄새가 k만큼 남은 곳이면 현재 이동 중인 상어를 삭제 처리(alive = false). (번호가 작은 상어부터 처리하기 때문에 비교 과정 필요 없음)
이동 가능한 칸의 수 = 0 이면, ocean[i][j].smell_num == shark_num인 칸으로 이동 우선순위 적용하여 이동.
*/
void move_shark(){ //상어를 번호대로 이동시킴
    for(int i = 1; i <= m; i++){
        if(shark[i].alive == false) continue; // 격자에서 쫓겨난 상어이면 실행X
        int x = shark[i].x;
        int y = shark[i].y;
        ocean[x][y].shark_num = 0; // 상어가 이동하기 떄문에 칸에 상어 정보 삭제
        pair<int, pair<int, int>> cell = move_cell(x, y, i); // 이동 가능한 칸의 좌표.
        // cout << "shark_num = " << i << " / x = " << x << " / y = " << y  << " / new_x = " << cell.second.first << " / new_y = " << cell.second.second << endl;
        if (ocean[cell.second.first][cell.second.second].shark_num == 0){ // 빈칸 혹은 자신의 칸이면 정보 갱신
            if(ocean[cell.second.first][cell.second.second].smell_num == 0){ // 새로운 칸이면 도착 정보 추가
                ocean[cell.second.first][cell.second.second].arrive_now = true;
            }
            ocean[cell.second.first][cell.second.second].shark_num = i;
            ocean[cell.second.first][cell.second.second].smell_num = i;
            ocean[cell.second.first][cell.second.second].smell_left = k;
            shark[i].x = cell.second.first;
            shark[i].y = cell.second.second;
            shark[i].looking_dir = cell.first;
        } else if(ocean[cell.second.first][cell.second.second].shark_num < i){ // 같은 시점에 이동한 번호 낮은 상어가 있을 때
            // cout << "MOVE BLANK" << endl;
            shark[i].alive = false;
            cnt_shark -= 1; // 상어 수 감소
        }
        // cout << i << "의 보는 방향 : " << point[cell.first-1] << endl;
    }
}


//상어 이동한 뒤 냄새 시간 1 감소
void solve(){
    cnt_shark = m;
    while(sec < 1000){
    // while(sec <= 1000){
        // cout << "SECOND = " << sec << endl;
        sec += 1;
        // print_ocean();
        move_shark();
        dec_smell();
        if(cnt_shark == 1){ // 1번 상어만 남으면
            cout << sec;
            return;
        }
        // cout << endl;
    }
    cout << -1; // 1000초가 넘었는데 상어가 여러마리 남았을 때
    return;
}

int main(){
    input();
    solve();
}

/*
지도에 대한 정보: 좌표에 존재하는 상어 번호&유무, 냄새 뿌린 상어 번호, 냄새 남은 시간
상어에 대한 정보: 현재 위치한 좌표, 현재 보고있는 방향, 우선순위 방향

상어는 한 번 이동할 때 1초가 걸림. sec가 1000보다 작거나 같을 때까지 반복
상어를 번호순서대로 이동시킴.
*/

/*
↑일 때 | ↑ ↓ ← →    
↓일 때 | ↓ ← → ↑    
←일 때 | ← → ↑ ↓    
→일 때 | → ↑ ↓ ←    
*/

// 자신이 있던 칸으로 돌아왔을 때, 그 칸은 K이기 때문에 기존에 비어있던 칸이라고 오해해서 생기는 버그