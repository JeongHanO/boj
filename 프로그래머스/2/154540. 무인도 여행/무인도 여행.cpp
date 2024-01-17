#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[i].size(); j++){
            if(!visited[i][j] && maps[i][j] != 'X'){
                int cnt = maps[i][j]-'0';
                visited[i][j] = true;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()){
                    pair<int, int> loc = q.front();
                    q.pop();
                    for(int x = 0; x < 4; x++){
                        int nx = loc.first + dx[x];
                        int ny = loc.second + dy[x];
                        if(nx >= 0 && nx < maps.size() && ny >= 0 && ny < maps[i].size() && maps[nx][ny] != 'X' && !visited[nx][ny]){
                            cnt += maps[nx][ny]-'0';
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                answer.push_back(cnt);
            }
        }
    }
    
    if(answer.empty()) return {-1};
    
    sort(answer.begin(), answer.end(), less<>());
    
    return answer;
}