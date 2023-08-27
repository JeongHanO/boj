#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int wolves = 0, sheeps = 0;
int ansWolves = 0, ansSheeps = 0;
int r, c;
char arr[250][250];
bool visieted[250][250];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    
    int cntWolf = 0;
    int cntSheep = 0;
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        if(arr[a][b] == 'k') cntSheep++;
        else if(arr[a][b] == 'v') cntWolf++;
        q.pop();
        for(int i= 0; i < 4; i++){
            int nx = a + dx[i];
            int ny = b + dy[i];
            if(!visieted[nx][ny] && arr[nx][ny] != '#' && nx >= 0 && nx < r && ny >= 0 && ny < c){
                visieted[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
    if(cntSheep > cntWolf) ansSheeps += cntSheep;
    else ansWolves += cntWolf;
}

int main(){
    cin >> r >> c;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            char a;
            cin >> a;
            if(a == 'v') wolves++;
            else if(a == 'k') sheeps++;
            arr[i][j] = a;
        }
    }
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(!visieted[i][j] && arr[i][j] != '#') {
                visieted[i][j] = true;
                bfs(i,j);
            }
        }
    }

    cout << ansSheeps << ' ' << ansWolves;
    return 0;
}