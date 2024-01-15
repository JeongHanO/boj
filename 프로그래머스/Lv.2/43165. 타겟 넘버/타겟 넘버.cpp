#include <vector>
using namespace std;

int answer = 0;
int depth = 0;
int target = 0;
vector<int> n;

void dfs(int sum, int idx){
    if(idx == depth){
        if(sum == target){
            answer++;
        }
        return;
    }
    dfs(sum+n[idx], idx+1);
    dfs(sum-n[idx], idx+1);
    
    return;
}


int solution(vector<int> num, int t) {
    for(int i = 0; i < num.size(); i++){
        n.push_back(num[i]);
    }
    
    depth = num.size();
    target = t;
    dfs(0, 0);

    return answer;
}