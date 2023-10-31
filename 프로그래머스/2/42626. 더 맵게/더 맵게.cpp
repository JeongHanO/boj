#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> sc, int K) {
    int answer = 0;
    priority_queue<int> q;
    for(auto it: sc){
        q.push(-it);
    }
    while((-1)*(q.top()) < K){
        answer += 1;
        long long tmp = 0;
        long long a, b;
        a = -q.top();
        q.pop();
        if(q.empty()) return -1;
        b = -q.top() * 2;
        q.pop();
        tmp = a + b;
        q.push(-tmp);
    }
    return answer;
}