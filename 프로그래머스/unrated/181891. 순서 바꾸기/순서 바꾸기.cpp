#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num, int n) {
    vector<int> answer;
    for(int i = n; i < num.size(); i++){
        answer.push_back(num[i]);
    }
    for(int i = 0; i < n; i++){
        answer.push_back(num[i]);
    }
    return answer;
}