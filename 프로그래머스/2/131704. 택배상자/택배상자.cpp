#include <string>
#include <vector>
#include <stack>
using namespace std;

stack<int> stk;

int solution(vector<int> order) {
    int answer = 0;
    
    int idx = 0; // 컨테이너 벨트 가장 앞의 상자
    for(int i = 0; i < order.size(); i++){
        if(order[i] == idx){
            idx += 1;
            answer += 1;
        }
        else if(order[i] > idx){
            while(order[i] > idx){
                stk.push(idx);
                idx += 1;
            }
            if(order[i] == idx){
                idx += 1;
                answer += 1;
            }
        }
        else if(order[i] < idx){
            if(order[i] == stk.top()){
                answer += 1;
                stk.pop();
            }
            else{
                break;
            }
        }
    }
    
    return answer;
}