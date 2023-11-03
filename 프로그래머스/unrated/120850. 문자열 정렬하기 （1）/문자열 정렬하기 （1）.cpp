#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i])){
            answer.push_back(s[i]-'0');
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}