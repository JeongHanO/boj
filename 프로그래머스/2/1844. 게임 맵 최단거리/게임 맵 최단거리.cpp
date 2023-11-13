#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int map [100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    queue<pair<int, int>> q;
    q.push({0,0});
    map[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < maps.size() && ny >= 0 && ny < maps[i].size() && maps[nx][ny] && map[nx][ny] == 0){
                map[nx][ny] = map[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    if(map[maps.size()-1][maps[0].size()-1] == 0) return -1;
    else return map[maps.size()-1][maps[0].size()-1];
    
    return answer;
}