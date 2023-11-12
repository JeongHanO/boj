#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    for(int i = 0; i < s.size(); i++){
        answer += tolower(s[i]);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}