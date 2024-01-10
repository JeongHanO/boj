#include <string>
#include <vector>

using namespace std;

vector<string> solution(string s, int n) {
    vector<string> answer;
    
    for(int i = 0; i < s.length(); i += n){
        string str = s.substr(i, n);
        answer.push_back(str);
    }
    
    return answer;
}