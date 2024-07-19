#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    if (num_list.size()<11){
        answer++;
        for (auto n : num_list){
            answer *= n;
        }
    }
    else{
        for (auto n:num_list) answer += n;
    }
    
    return answer;
}