#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> a) {
    vector<int> answer;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[i]; j++){
            answer.push_back(a[i]);
        }
    }
    return answer;
}