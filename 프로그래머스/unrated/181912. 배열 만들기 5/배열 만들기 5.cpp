#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> in, int k, int s, int l) {
    vector<int> answer;
    
    for(int i = 0; i < in.size(); i++){
        string st = in[i].substr(s, l);
        if(stoi(st) > k) answer.push_back(stoi(st));
    }
    
    return answer;
}