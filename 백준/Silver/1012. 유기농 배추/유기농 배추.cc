#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int t;
int m, n, k;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    cin >> t;
    while(t--){
        int ans = 0;
        cin >> m >> n >> k;
        vector<vector<bool>> board(n, vector<bool>(m,false));
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        while(k--){
            int ans = 0;
            int x, y;
            cin >> x >> y;
            board[y][x] = true;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == true && visited[i][j] == false){
                    ans++;
                    visited[i][j] = true;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int k = 0; k < 4; k++){
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == true && visited[nx][ny] == false){
                                q.push({nx, ny});
                                visited[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}