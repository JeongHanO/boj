#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> p, int location) {
    int answer = 0;
    
    queue<pair<int, bool>> q;    
    for(int i = 0 ; i < p.size(); i++){
        if(i == location){
            q.push(make_pair(p[i], true));    
        } else{
            q.push(make_pair(p[i], false));
        }
    }
    
    sort(p.begin(), p.end());
    
    for(int i = p.size()-1; i >= 0; i--){
        while(1){
            pair<int, bool> pa = q.front();
            q.pop();
            if(p[i] == pa.first){ // 가장 높은 우선순위이면
                if(pa.second == true){ // location번 요소이면
                    return p.size()-i;
                }
                break;
            } else{
                q.push(pa);
            }
        }
    }
    
    return answer;
}