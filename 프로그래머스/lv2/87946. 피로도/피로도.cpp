#include <string>
#include <vector>

using namespace std;

bool visited[8];
int answer = -1;

void dfs(int k, vector<vector<int>> dungeons, int depth){
    for(int i = 0; i < dungeons.size(); i++){
        if(!visited[i] && k >= dungeons[i][0]){
            visited[i] = true;
            dfs(k - dungeons[i][1], dungeons, depth+1);
            visited[i] = false;
        }
    }
    if(answer < depth) answer = depth;
}

int solution(int k, vector<vector<int>> dungeons) {
    
    
    // 테스트 케이스가 적으니 완전 탐색으로 해도 될듯
    dfs(k, dungeons, 0);
    
    return answer;
}