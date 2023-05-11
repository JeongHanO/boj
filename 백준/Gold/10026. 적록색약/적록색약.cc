#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
char color_map[100][100];
bool visited[100][100]={false,};

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


void bfs(int x, int y){
    pair<int, int> p;
    p = make_pair(x,y);
    queue<pair<int,int> > q;
    q.push(p);
    visited[x][y] = true;
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = a + dx[i];
            int ny = b + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n && !visited[nx][ny] && color_map[nx][ny] == color_map[a][b]){
                visited[nx][ny] = true;
                p=make_pair(nx,ny);
                q.push(p);
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i= 0;i<n;i++){
        for(int j=0;j<n;j++){
            char a;
            cin >> a;
            
            if(a == 'R'){ color_map[i][j] = 'R'; }
            else if(a =='G'){ color_map[i][j] = 'G'; }
            else{ color_map[i][j] = 'B'; }
        }
    }
    int rg = 0;
    int nrg = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                bfs(i,j);
                nrg++;
            }
        }
    }
    cout << nrg << ' ';
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j] = false;
            if(color_map[i][j] == 'G'){
                color_map[i][j] = 'R';
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                bfs(i,j);
                rg++;
            }
        }
    }
    cout << rg;
    return 0;
}
