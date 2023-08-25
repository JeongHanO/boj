#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, depth;
int cnt = 0, num = 1;
vector<int> barn[20001];
bool visited[20001];

void bfs(int dep, int start){
    queue<pair<int, int> > q;
    q.push(make_pair(start, dep));
    visited[1] = true;
    depth = 0;

    while(!q.empty()){
        int a= q.front().first;
        int b= q.front().second;
        q.pop();
        if(b > depth) {
            depth = b;
            num = a;
            cnt = 1;
        } else if(b == depth){
            if(num > a) num = a;
            cnt++;
        }
        for(int i = 0; i < barn[a].size(); i++){
            if(!visited[barn[a][i]]){
                visited[barn[a][i]] = true;
                q.push(make_pair(barn[a][i], b+1));
            }
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        barn[a].push_back(b);
        barn[b].push_back(a);
    }

    bfs(0, 1);

    cout << num << ' '<< depth << ' ' << cnt;
    return 0;
}