#include <string>
#include <vector>

using namespace std;

string solution(string s, vector<int> idx) {
    string answer = "";
    for(int i = 0; i < idx.size(); i++){
        answer += s[idx[i]];
    }
    return answer;
}