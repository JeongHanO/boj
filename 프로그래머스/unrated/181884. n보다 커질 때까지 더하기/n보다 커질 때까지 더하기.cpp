#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num, int n) {
    int answer = 0;
    
    for(int i = 0; i < num.size(); i++){
        if(answer + num[i] > n) return answer + num[i];
        else answer += num[i];
    }
    return answer;
}