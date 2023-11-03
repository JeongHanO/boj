#include <string>
#include <vector>

using namespace std;

string solution(string m) {
    string answer = "";
    for(int i= 0; i < m.size(); i++){
        if(m[i] >= 'A' && m[i] <= 'Z'){
            answer += tolower(m[i]);
        } else {
            answer += toupper(m[i]);
        }
    }
    return answer;
}