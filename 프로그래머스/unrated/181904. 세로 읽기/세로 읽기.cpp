#include <string>
#include <vector>

using namespace std;

string solution(string s, int m, int c) {
    string answer = "";
    for(int i = c-1; i < s.size(); i += m){
        answer += s[i];
    }
    return answer;
}