#include <iostream>
#include <vector>
using namespace std;

int n;
int ans = 0;
int board[21][21]; // 자리 배치
vector<vector<int> > stu_like(401); // 학생들의 선호 학생 저장

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void placement(int stu_num){
    pair<pair<int, int>, pair<int, int> > pos = {make_pair(-1, -1), make_pair(-1, -1)}; // {{빈 자리 수, 선호 학생 수}, {좌표}}
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            if(board[x][y] != 0) continue; // 빈자리가 아니면 패스
            int empty = 0;
            int like_cnt = 0;
            for(int i = 0; i < 4; i++){ //주변에 있는 칸 분별
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue; // 범위 벗어나면 생략
                if(board[nx][ny] == 0){ // 빈 칸 카운트
                    empty++;
                    continue;
                }
                for(int j = 0; j < 4; j++){ // 좋아하는 학생 카운트
                    if(board[nx][ny] == stu_like[stu_num][j]){
                        like_cnt++;
                        break;
                    }
                }
            }
            if(like_cnt > pos.first.second) pos = {{empty, like_cnt}, {x, y}}; // 선호 학생 수 더 많음
            else if(like_cnt == pos.first.second && empty > pos.first.first) pos = {{empty, like_cnt}, {x, y}}; // 선호 학생 수 동일, 빈 칸 수 많음
        }
    }
    board[pos.second.first][pos.second.second] = stu_num; // 자리 배치
}

void like_sum(){
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            int like_cnt = 0;
            for(int i = 0; i < 4; i++){ //주변에 있는 칸 분별
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue; // 범위 벗어나면 생략
                for(int j = 0; j < 4; j++){ // 좋아하는 학생 카운트
                    if(board[nx][ny] == stu_like[board[x][y]][j]){
                        like_cnt++;
                        break;
                    }
                }
            }
            if(like_cnt == 1) ans += 1;
            if(like_cnt == 2) ans += 10;
            if(like_cnt == 3) ans += 100;
            if(like_cnt == 4) ans += 1000;
        }
    }
}

int main(){
    cin >> n;
    
    for(int i = 0; i < n*n; i++){
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        vector<int> tmp_v = {b, c, d, e};
        stu_like[a] = tmp_v;
        placement(a);
    }

    like_sum();

    cout << ans << endl;
}