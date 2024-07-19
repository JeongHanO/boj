#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    
    for (auto n:arr){
        if (k%2==1) answer.emplace_back(n*k);
        else answer.emplace_back(n+k);
    }
    
    return answer;
}