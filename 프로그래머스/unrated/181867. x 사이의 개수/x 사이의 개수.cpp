#include <string>
#include <vector>

using namespace std;

vector<int> solution(string m) {
    vector<int> answer;
    int a = 0;
    for(int i = 0; i < m.size(); i++){
        if(m[i] == 'x'){
            answer.push_back(a);
            a = 0;
        } else{
            a += 1;
        }
    }
    answer.push_back(a);
    return answer;
}