#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> n) {
    vector<int> answer;
    sort(n.begin(), n.end());
    for(int i = 5; i < n.size(); i++){
        answer.push_back(n[i]);
    }
    return answer;
}