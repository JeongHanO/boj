#include <string>
#include <vector>

using namespace std;

vector<string> solution(string m) {
    vector<string> answer;
    string s = "";
    for(int i = 0; i < m.size(); i++){
        if(m[i] != ' '){
            s += m[i];
        } else {
            if(s.size() > 0) answer.push_back(s);
            s = "";
        }
    }
    if(s.size() > 0) answer.push_back(s);
    return answer;
}