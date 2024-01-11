#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r, c;
char board[51][51];
int cnt[51][51];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

queue<pair<int, int>> wq;
queue<pair<int, int>> hq;

int main(){
    cin >> r >> c;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            char ch;
            cin >> ch;
            board[i][j] = ch;
            if(ch == 'S'){
                hq.push({i, j});
            } else if(ch == '*'){
                wq.push({i, j});
            }
        }
    }
    
    while(!hq.empty()){
        int w_len = wq.size();
        for(int i = 0; i < w_len; i++){
            pair<int, int> water = wq.front();
            wq.pop();
            for(int j = 0; j < 4; j++){
                int nx = water.first + dx[j];
                int ny = water.second + dy[j];
                if(nx >= 0 && nx < r && ny >= 0 && ny < c && board[nx][ny] == '.' && board[nx][ny] != 'X'){
                    board[nx][ny] = '*';
                    wq.push({nx, ny});
                }
            }
        }
        int h_len = hq.size();
        for(int i = 0; i < h_len; i++){
            pair<int, int> hog = hq.front();
            hq.pop();
            for(int j = 0; j < 4; j++){
                int nx = hog.first + dx[j];
                int ny = hog.second + dy[j];
                
                if(nx >= 0 && nx < r && ny >= 0 && ny < c && board[nx][ny] != '*' && board[nx][ny] != 'X' && cnt[nx][ny] == 0){
                    cnt[nx][ny] = cnt[hog.first][hog.second] + 1;
                    if(board[nx][ny] == 'D'){
                        cout << cnt[nx][ny] << endl;
                        return 0;
                    }
                    hq.push({nx, ny});
                }
            }
        }
    }

    cout << "KAKTUS";

    return 0;
}