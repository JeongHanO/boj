#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int ans = 0;
    int now = 0;
    
    priority_queue<pair<int, int>> pq1; // 앞으로 남은 프로세스. 요청 시간 순으로 정렬
    priority_queue<pair<int, int>> pq2; // 현재 시간에 아직 완료하지 못한 프로세스, 소요 시간 순으로 정렬.
    
    for(int i = 0; i < jobs.size(); i++){
        pq1.push({-jobs[i][0], jobs[i][1]}); // 요청시간이 작은 순으로 정렬
    }
    
    while(!pq1.empty()){ // 시간에 따른 프로세스 요청이 완료될 때 까지.
        if(pq2.empty()){ // 현재 진행 중인 프로세스와 실행 대기 중인 프로세스가 없을 때.
            if(now < -pq1.top().first) now = -pq1.top().first; // 현재 시간에 수행할 수 있는 프로세스가 없을 때, 시간을 앞으로.
        }
        while(!pq1.empty() && -pq1.top().first <= now){
            pq2.push({-pq1.top().second, -pq1.top().first}); // 요청 시간이 작은 순서대로 저장. 요청 시간 부호 정상화.
            pq1.pop();
        }
        
        now += -pq2.top().first; // 가장 짧은 프로세스 수행을 마친 시간.
        ans += now - pq2.top().second;
        pq2.pop();
    }
    
    while(!pq2.empty()){ // 모든 프로세스 완료하기
        now += -pq2.top().first;
        ans += now - pq2.top().second;
        pq2.pop();
    }
    
    return ans/jobs.size();
}
/*
현재 시점(어떤 프로세스가 마친 시점)에서 처리할 수 있는 가장 짧은 시간의 프로세스를 먼저 처리 하는 것이 이득.
힙을 두 개 사용.
1번 힙: 요청 시간이 빠른 순서대로 정렬된 힙. 현재 시간과 비교해서 heap에서 pop하고 2번 힙에 push.
2번 힙: 소요시간이 작은 순서대로 정렬된 힙. 소요시간이 가장 작은 프로세스를 진행하고, 종료 시점에 따라 현재 시간을 갱신.
*/