#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    string s = to_string(order);
    for(auto i: s){
        if((i-'0')%3==0 && i>'0') answer += 1;
    }
    return answer;
}