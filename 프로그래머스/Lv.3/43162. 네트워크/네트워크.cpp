#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> v(201);
bool visited[201];

int solution(int n, vector< vector<int> > c) { 
    int answer = 0;
    
    for(int i = 0; i < c.size(); i++){
        for(int j = 0; j < c[i].size(); j++){
            if(i == j) continue;
            if(c[i][j] == 1){
                v[i].push_back(j);
            }
        }
    }
    
    for(int i = 0; i < c.size(); i++){
        if(visited[i] == false){ // 탐색 기록 없는 노드
            queue<int> q;
            q.push(i);
            visited[i] = true;
            answer++;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int j = 0; j < v[node].size(); j++){
                    if(visited[v[node][j]] == false){
                        q.push(v[node][j]);
                        visited[v[node][j]] = true;    
                    }
                }
            }
        }
    }

    return answer;
}

/*
1번 노드부터 순회하면서 연결되어 있는 노드들을 방문, 방문하면 visited에 기록을 남김. -> visited[node] = true;
방문한 노드에 연결된 노드들도 추가로 방문하기 위해 queue에 넣음.

다음 노드로 넘어갈 때, 이미 방문한 노드는 탐색을 시작하지 않도록 함.
*/