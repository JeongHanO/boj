#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int m, n;
vector<vector<int>> v(1001, vector<int>(1001));
vector<vector<bool>> visited(1001, vector<bool>(1001, false));


int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool bfs(int a){
    queue<pair<int, int>> q;
    q.push({0,a});
    visited[0][a] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && v[nx][ny] == 0 && visited[nx][ny] == false){
                visited[nx][ny] = true;
                q.push({nx, ny});
                if(nx == m-1) return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> m >> n;

    for(int i = 0; i < m; i++){
        string s; cin >> s;
        for(int j = 0; j < n; j++){
            v[i][j] = s[j]-'0';
        }
    }

    for(int i = 0; i < n; i++){
        if(v[0][i] == 0){
            if(bfs(i)){
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";

    return 0;
}