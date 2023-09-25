#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            answer += ' ';
            continue;
        }
        char c;
        if(isupper(s[i])){
            c = s[i] + n;
            if(c > 'Z') c -= 26;
        } else{
            s[i]+n > 'z' ? c = s[i] + n - 26 : c = s[i] + n;
        }
        answer += c;
    }
    return answer;
}