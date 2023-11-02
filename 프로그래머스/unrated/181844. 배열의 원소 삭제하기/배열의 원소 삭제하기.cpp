#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> a, vector<int> d) {
    vector<int> answer;
    for(int i = 0; i < a.size(); i++){
        bool t = true;
        for(int j = 0; j < d.size(); j++){
            if(a[i] == d[j]){
                t = false;
                break;
            }
        }
        if(t){
            answer.push_back(a[i]);
        }
    }
    return answer;
}