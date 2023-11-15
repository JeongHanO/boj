#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[20001];
vector<vector<int>> v(20001);
vector<int> depth(20001);

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i = 0; i < edge.size(); i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(int i = 0; i < v[a].size(); i++){
            if(!visited[v[a][i]]){
                int tmp_depth = depth[a] + 1;
                q.push(v[a][i]);
                visited[v[a][i]] = true;
                depth[v[a][i]] = tmp_depth;
            }
        }
    }
    
    sort(depth.begin(), depth.end(), greater<int>());
    for(auto it: depth){
        if(it != depth[0]) break;
        answer += 1;
    }
    
    return answer;
}