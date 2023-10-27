#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> t, vector<bool> f) {
    vector<string> answer;
    for(int i = 0; i < t.size(); i++){
        if(!f[i]) answer.push_back(t[i]);
    }
    return answer;
}