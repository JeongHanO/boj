#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    bool zero = true;
    for(int i = 0; i < code.size(); i++){
        if(code[i]=='1'){
            zero = !zero;
            continue;
        }
        if(zero){
            if(i%2 == 0) answer += code[i];
        } else {
            if(i%2) answer += code[i];
        }
    }
    if(answer.empty()) return "EMPTY";
    return answer;
}