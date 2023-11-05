#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool visited[50];

bool dif_one(string a, string b){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) cnt += 1;
    }
    if(cnt == 1) return true;
    return false;
}

int bfs(string b, string t, vector<string> words){
    int answer = 0;
    
    queue<string> q;
    q.push(b);
    
    while(!q.empty()){
        int k = q.size();
        while(k--){
            string s = q.front();
            q.pop();
            cout << s << endl;
            if(s == t) return answer;
            for(int i = 0; i < words.size(); i++){
                if(!visited[i] && dif_one(s, words[i])){
                    q.push(words[i]);
                    visited[i] = true;
                }
            }    
        }
        
        answer += 1;
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int a = bfs(begin, target, words);
    return a;
}

/*
BFS로 현재 단어와 하나만 차이나는 단어를 찾아가며 target까지 갈 수 있는지 탐색
queue에 
visited로 이미 확인한 단어인지 봐야함.

*/