#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    for(int i = 0; i < n; i++){
        vector<int> tmp;
        for(int j = 0; j < n; j++){
            if(j == i) tmp.push_back(1);
            else tmp.push_back(0);
        }
        answer.push_back(tmp);
    }
    return answer;
}