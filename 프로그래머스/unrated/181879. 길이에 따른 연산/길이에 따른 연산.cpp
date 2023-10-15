#include <string>
#include <vector>

using namespace std;

int solution(vector<int> n) {
    int answer = 0;
    if(n.size() > 10)
        for(int i = 0; i < n.size(); i++)
            answer += n[i];
    else{
        answer = 1;
        for(int i = 0; i < n.size(); i++){
            answer *= n[i];
        }
    }        
    
    return answer;
}