#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> in) {
    int answer = 0;
    
    if(in[0]) answer += a;
    for(int i = 1; i < in.size(); i++){
        a += d;
        if(in[i]) answer += a;
    }
    
    return answer;
}