#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int board[101][101]; // 빈칸: 0, 사과: 1, 뱀: 2
int n, k;
int sec = 1; // 진행 시간
int dir = 0; // 우0, 하1, 좌2, 상3

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

deque<pair<int, int>> snake;
queue<pair<int, char>> movement;

void input(){
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        board[x-1][y-1] = 1;
    }

    int l;
    cin >> l;
    for(int i = 0; i < l; i++){
        int a;
        char c;
        cin >> a >> c;
        movement.push({a, c});
    }
    snake.push_back({0, 0});
    board[0][0] = 2;
}

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

void start(){
    while(10){
        int nx = snake.front().first + dx[dir];
        int ny = snake.front().second + dy[dir];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] == 2) break; // 벽 or 뱀
        if(board[nx][ny] == 0){ // 빈칸
            board[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
            board[nx][ny] = 2;
            snake.push_front({nx, ny});
        }
        else if(board[nx][ny] == 1){ // 사과
            snake.push_front({nx, ny});
            board[nx][ny] = 2;
        }
        if(movement.front().first == sec){ // 진행 방향 변경
            if(movement.front().second == 'D') dir++; // 오른쪽 회전
            else dir--; // 왼쪽 회전
            dir = (dir+4) % 4;
            movement.pop();
        }
        sec++;
    }
}

int main(){
    input();
    start();
    cout << sec << endl;
}