#include <string>
#include <vector>

using namespace std;

string solution(string n) {
    string answer = "";
    bool no = true;
    for(int i = 0; i < n.size(); i++){
        if(no && n[i] == '0'){
            continue;
        }
        if(n[i] != '0'){
            no = false;
        }
        answer += n[i];
    }
    return answer;
}