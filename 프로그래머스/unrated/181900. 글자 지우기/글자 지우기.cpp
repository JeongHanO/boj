#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, vector<int> in) {
    string answer = "";
    int idx = 0;
    sort(in.begin(), in.end());
    for(int i = 0; i < s.size(); i++){
        if(i == in[idx]){
            idx += 1;
            continue;
        }
        answer += s[i];
    }
    return answer;
}