#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> p, vector<int> s) {
    vector<int> answer;
    
    int idx = 0;
    while(idx < p.size()){
        for(int i = 0; i < p.size(); i++){
            p[i] += s[i];
        }
        int cnt = 0;
        for(int i = idx; i < p.size(); i++){
            if(p[i] >= 100){
                cnt += 1;
                idx += 1;
            } else {
                break;
            }
        }
        if(cnt > 0){
            answer.push_back(cnt);
        }
    }
    
    return answer;
}