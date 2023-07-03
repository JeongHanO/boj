#include <iostream>
#include <queue>
using namespace std;

int n, m;
int W, B;
char battlefield[100][100];
bool visited[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int a, int b){
    int cnt = 1;
    char color = battlefield[a][b];
    visited[a][b] = true;

    queue<pair<int, int> > q;
    q.push(make_pair(a, b));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0;i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && battlefield[nx][ny] == color){
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
                cnt++;
            }
        }
    }
    return cnt * cnt;
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> battlefield[j][i];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[j][i]){
                if(battlefield[j][i] == 'W'){
                    W += bfs(j, i);
                }
                else{
                    B += bfs(j, i);
                }
            }
        }
    }

    cout << W << ' ' << B;
}