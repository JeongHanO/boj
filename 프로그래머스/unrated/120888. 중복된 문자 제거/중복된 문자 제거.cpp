#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    
    for(int i = 0; i < s.size(); i++){
        bool is = false;
        for(int j = 0; j < answer.size(); j++){
            if(s[i] == answer[j]){
                is = true;
            }
        }
        if(!is) answer += s[i];
    }
    
    return answer;
}