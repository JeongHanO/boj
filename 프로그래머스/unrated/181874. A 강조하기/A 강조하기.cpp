#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    for(int i = 0 ; i < s.size(); i++){
        if(s[i] == 'a' || s[i] == 'A'){
            answer += 'A';
        } else{
            answer += tolower(s[i]);
        }
    }
    return answer;
}