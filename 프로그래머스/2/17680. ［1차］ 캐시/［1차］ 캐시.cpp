#include <string>
#include <vector>

using namespace std;

int solution(int cache, vector<string> c) {
    int answer = 0;
    vector<string> v;
    if(cache == 0) return 5*c.size();
    for(int i = 0; i < c.size(); i++){
        string s = "";
        for(int j = 0; j < c[i].size(); j++){
            s += tolower(c[i][j]);
        }
        
        bool found = false;
        for(int j = 0; j < v.size(); j++){
            if(s == v[j]){
                answer += 1;
                found = true;
                v.erase(v.begin()+j);
                v.push_back(s);
                break;
            }
        }
        if(!found){
            if(v.size() == cache && cache > 0){
                v.erase(v.begin());
            }
            v.push_back(s);
            answer += 5;
        }
    }
    
    return answer;
}
/*
캐시 벡터를 확인하면서 값이 존재하면 벡터의 가장 뒤로 이동.
*/