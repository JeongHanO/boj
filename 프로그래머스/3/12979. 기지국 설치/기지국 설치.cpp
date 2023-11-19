#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int idx = 0;
    int location = 1;
    while(location <= n){
        if(stations[idx] - w > location || stations[idx] + w < location){ // 현재 위치에서 가장 가까운 기지국이 영향을 못 미칠 때
            //새로운 기지국 설치
            answer += 1;
            location += 2*w+1;
        }else if(stations[idx] - w <= location || stations[idx] + w >= location){ // 현재 위치가 기지국의 영향을 받음
            location = stations[idx] + w + 1;
            idx += 1;
        }
    }

    return answer;
}