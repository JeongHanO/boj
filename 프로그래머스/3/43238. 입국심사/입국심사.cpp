#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> t;

unsigned long long solution(int n, vector<int> times) {
    unsigned long long answer = 0;
    
    sort(times.begin(), times.end());
    
    unsigned long long l = 1; // 모든 사람을 처리하는데 걸리는 최소 시간 (1*n)
    unsigned long long r = times.back() * n; // 모든 사람을 처리하는데 걸리는 최대 시간 (max_time*n)
    
    while(l <= r){
        unsigned long long mid = (l+r)/2; // 모든 사람을 처리하는데 걸리는 평균 시간
        unsigned long long cnt = 0;
        
        for(int i: times){
            cnt += mid/i; // 평균 시간동안 처리할 수 있는 사람의 수
        }
        
        if(cnt >= n){ // 처리가능한 사람의 수가 기다리는 사람의 수보다 많음 -> 처리 시간이 줄어드는 경우도 탐색
            if(answer == 0){
                answer = mid;
            } else{
                answer = min(answer, mid);
            }
            r = mid - 1;
        } else{ // 처리가능한 사람의 수가 기다리는 사람의 수보다 적음 -> 처리 시간을 늘려야함
            l = mid + 1;
        }
    }
    
    return answer;
}