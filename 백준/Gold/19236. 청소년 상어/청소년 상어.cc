#include <iostream>
#include <vector>
#include <map>
using namespace std;

int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
string dir_point[] = { "0", "↑", "↖", "←", "↙", "↓", "↘", "→", "↗" };

struct FISH {
    int x;
    int y;
    int dir;
    bool is_live;
};

FISH fishes[20];
int ocean[4][4];
int answer = 0;

void input() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int a, b;
            cin >> a >> b;
            ocean[i][j] = a;
            fishes[a] = {i, j, b, true};
        }
    }
}

/*
이동할 공간에 대해서 범위 체크, 상어 없는지 체크.
이동 가능하면 이동할 자리에 있는 물고기와 자리 교환
이동 불가능하면 ocean[i][j].second 값을 1 증가, 다시 처음으로
*/
void move_fish(int fish_num, int fish_x, int fish_y) { // 특정 번호 물고기 이동
    int fish_dir_now = fishes[fish_num].dir;
    for (int i = 0; i < 8; i++) { // 모든 방향에 대해 검사
        int fish_dir = fish_dir_now + i;
        if (fish_dir > 8) fish_dir %= 8;
        int fish_nx = fish_x + dx[fish_dir];
        int fish_ny = fish_y + dy[fish_dir];
        if (fish_nx >= 0 && fish_nx < 4 && fish_ny >= 0 && fish_ny < 4) { // 범위 내부
            if (ocean[fish_nx][fish_ny] != -1) { // 상어와 다른 위치
                fishes[fish_num].dir = fish_dir; // 이동방향 저장
                if (ocean[fish_nx][fish_ny] > 0) { // 물고기가 있음
                    int tmp = ocean[fish_nx][fish_ny];
                    ocean[fish_nx][fish_ny] = ocean[fish_x][fish_y];
                    ocean[fish_x][fish_y] = tmp;
                    fishes[ocean[fish_x][fish_y]].x = fish_x;
                    fishes[ocean[fish_x][fish_y]].y = fish_y;
                }
                else { // 빈칸
                    ocean[fish_nx][fish_ny] = ocean[fish_x][fish_y];
                    ocean[fish_x][fish_y] = 0;
                }
                fishes[fish_num].x = fish_nx;
                fishes[fish_num].y = fish_ny;

                return; // 자리 변경했으면 이동 종료
            }
        }
    }
}

void move_fishes() { // 물고기 번호대로 이동
    for (int i = 1; i <= 16; i++) {
        if (fishes[i].is_live == false) continue;
        move_fish(i, fishes[i].x, fishes[i].y);
    }
}

void copy_state(int a[][4], int b[][4], FISH c[], FISH d[]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a[i][j] = b[i][j];
        }
    }
    for (int i = 1; i <= 16; i++) {
        c[i] = d[i];
    }
}

// 바다 상태 & 물고기 상태 업데이트 및 복원
void update_state(int x, int y, int nx, int ny, int fish_num, bool update) {
    if (update) { // 상어가 이동 & 물고기 사라짐
        ocean[x][y] =0;
        ocean[nx][ny] = -1;
        fishes[fish_num].is_live = false;
    }
    else { // 상어 복원 & 물고기 복원
        ocean[x][y] = -1;
        ocean[nx][ny] = fish_num;
        fishes[fish_num].is_live = true;
    }
}

/*
현재 상태의 ocean, fish 상태를 임시로 저장해놓은 뒤 물고기 이동.
(상어 이동 -> 재귀 -> 상어 이동 취소)순서로 모든 경우의 수 탐색.
앞서 저장해놓은 물고기 이동 원래대로 돌려놓기.
*/
void dfs(int x, int y, int dir, int sum) {
    answer = max(answer, sum);
    int c_ocean[4][4];
    FISH c_fishes[20];
    copy_state(c_ocean, ocean, c_fishes, fishes);
    move_fishes();
    for (int i = 1; i <= 3; i++) {
        int nx = x + dx[dir] * i;
        int ny = y + dy[dir] * i;
        if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) { //범위 내부
            if (ocean[nx][ny] != 0) { // 빈칸이 아니면
                int fish_num = ocean[nx][ny];
                int fish_dir = fishes[fish_num].dir;

                update_state(x, y, nx, ny, fish_num, true);
                dfs(nx, ny, fish_dir, sum + fish_num);
                update_state(x, y, nx, ny, fish_num, false);
            }
        }
        else break; // 범위 벗어나면 반복문 종료
    }

    copy_state(ocean, c_ocean, fishes, c_fishes);
}

void solve() {
    int fish_num = ocean[0][0];
    int dir = fishes[fish_num].dir;
    fishes[fish_num].is_live = false;

    ocean[0][0] = -1;
    dfs(0, 0, dir, fish_num);
    cout << answer;
}

int main() {
    input();
    solve();
    return 0;
}