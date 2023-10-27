#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] < 'l'){
            answer += 'l';
        } else answer += s[i];
    }
    return answer;
}