#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<vector<int>> v(101);

int bfs(int a, int b, vector<vector<int>> v){
    int cnt1 = 1, cnt2 = 1;
    queue<int> q1;
    q1.push(a);
    vector<bool> visited1(v.size(), false);
    visited1[a] = true;
    while(!q1.empty()){
        int x = q1.front();
        q1.pop();
        for(int i = 0; i < v[x].size(); i++){
            if(!visited1[v[x][i]]){
                visited1[v[x][i]] = true;
                q1.push(v[x][i]);
                cnt1++;
            }
        }
    }
    queue<int> q2;
    q2.push(b);
    vector<bool> visited2(v.size(), false);
    visited2[b] = true;
    while(!q2.empty()){
        int x = q2.front();
        q2.pop();
        for(int i = 0; i < v[x].size(); i++){
            if(!visited2[v[x][i]]){
                visited2[v[x][i]] = true;
                q2.push(v[x][i]);
                cnt2++;
            }
        }
    }
    return abs(cnt1 - cnt2);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1000000;
    
    for(int j = 0; j < wires.size(); j++){
        int a, b;
        vector<vector<int>> v(n+1);
        for(int i = 0; i < wires.size(); i++){
            if(i == j){
                a = wires[i][0];
                b = wires[i][1];
                continue;
            }
            v[wires[i][0]].push_back(wires[i][1]);
            v[wires[i][1]].push_back(wires[i][0]);
        }
        answer = min(answer, bfs(a, b, v));
    }
    
    return answer;
}