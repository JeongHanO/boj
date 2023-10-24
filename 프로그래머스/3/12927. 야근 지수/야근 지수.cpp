#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> q;
    for(auto i: works){
        q.push(i);
    }
    
    int num;
    while(n-- && !q.empty()){
        num = q.top();
        q.pop();
        if(num != 1) q.push(num-1);
    }
    while(!q.empty()){
        answer += q.top() * q.top();
        q.pop();
    }
    return answer;
}