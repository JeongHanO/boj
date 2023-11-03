#include <string>
#include <vector>

using namespace std;

string solution(string r) {
    string answer = "";
    for(int i = 0; i < r.size(); i++){
        if(r[i] == '2') answer += '0';
        else if (r[i] == '0') answer += '5';
        else answer += '2';
    }
    return answer;
}