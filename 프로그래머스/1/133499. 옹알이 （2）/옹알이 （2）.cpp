#include <string>
#include <vector>

using namespace std;

int solution(vector<string> b) {
    int answer = 0;
    
    for(int i = 0; i < b.size(); i++){
        string s;
        int idx = 0;
        for(int j = 0; j < b[i].size(); j++){
            s += b[i][j];
            if(s.size() == 2){
                if(s == "ye"){
                    if(idx == 1) break;
                    s = "";
                    idx = 1;
                } else if(s == "ma"){
                    if(idx == 2) break;
                    s = "";
                    idx = 2;
                }
            } else if(s.size() == 3){
                if(s == "aya"){
                    if(idx == 3) break;
                    s = "";
                    idx = 3;
                } else if(s == "woo"){
                    if(idx == 4) break;
                    s = "";
                    idx = 4;
                }
            }
        }
        if(s == ""){
            answer++;
        }
    }
    
    return answer;
}