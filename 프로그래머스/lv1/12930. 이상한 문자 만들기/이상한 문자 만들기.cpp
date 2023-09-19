#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool even = true;
    for(int i =0; i < s.size(); i++){
        if(s[i]==' '){
            answer += ' ';
            even = true;
            continue;
}
        if(even){
            answer += toupper(s[i]);
            even = false;
        } else {
            answer += tolower(s[i]);
            even = true;
        }
    }
    return answer;
}