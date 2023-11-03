#include <string>
#include <vector>

using namespace std;

string solution(vector<string> s, vector<vector<int>> p) {
    string answer = "";
    
    for(int i = 0; i < p.size(); i++){
        for(int j = p[i][0]; j <= p[i][1]; j++){
            answer += s[i][j];
        }
    }
    return answer;
}