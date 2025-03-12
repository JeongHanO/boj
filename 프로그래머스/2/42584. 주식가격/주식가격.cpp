#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int len = prices.size();
    
    vector<int> period(len, -1); // 자신보다 작은 값이 나오는 시점 기록
    vector<pair<int, int>> stk;
    
    stk.push_back({prices[0], 0});
    
    for(int i = 1; i < len; i++){
        if(prices[i] >= stk.back().first){
            stk.push_back({prices[i], i});
        }
        else{
            while(prices[i] < stk.back().first){
                period[stk.back().second] = i;
                stk.pop_back();
                if(stk.size() == 0){ // 비교 대상 없음
                    stk.push_back({prices[i],i});
                    break;
                }
            }
            stk.push_back({prices[i], i});
        }
    }
    
    for(int i = 0; i < len; i++){
        if(period[i] == -1){
            answer.push_back(len-i-1);
        }
        else{
            answer.push_back(period[i]-i);
        }
    }
    
    return answer;
}

/*
배열에 하나씩 추가하면서 제일 뒤와 숫자 비교.
커지거나 같으면 추가, 작아지면 pop.
추가하는 숫자보다 작거나 같은 수 나올 때까지 pop.
새로운 배열에 pop된 시점 기록.
*/