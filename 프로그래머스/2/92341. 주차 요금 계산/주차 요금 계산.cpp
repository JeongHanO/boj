#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int charge(vector<int> fees, int time){
    int fee = fees[1];
    if(time > fees[0]){ //기본 시간 초과
        fee += ceil(double(time-fees[0])/fees[2])*fees[3];
    }
    return fee;
}

vector<int> solution(vector<int> fees, vector<string> r) {
    vector<int> answer;
    map<int, int> time_m; //시간 기록용
    map<int, int> m; //입차 기록용
    
    for(int i = 0; i < r.size(); i++){
        int time = (r[i][0]-'0')*600 + (r[i][1]-'0')*60 + (r[i][3]-'0')*10 + (r[i][4]-'0');
        int num = stoi(r[i].substr(6,4));
        char cond = r[i][11];
        
        if(cond == 'I'){ //IN
            m.insert({num, time});
        }
        else{ //OUT
            int in_time = m[num];
            int out_time = time;
            int _time = out_time - in_time;
            m.erase(num);
            if(time_m.find(num) != time_m.end()){
                time_m[num] += _time;
            }
            else{
                time_m.insert({num, _time});
            }
        }
        
    }
    
    for(auto it= m.begin(); it != m.end(); it++){ //m에 남아있는 차들 - 23:59 출차
        int num = it->first;
        int time = 23*60+59 - it->second;
        if(time_m.find(num) != time_m.end()){
            time_m[num] += time;
        }
        else{
            time_m.insert({num, time});
        }
    }
    
    for(auto i = time_m.begin(); i != time_m.end(); i++){
        answer.push_back(charge(fees, i->second));
    }
    
    return answer;
}

/*
records를 순회하면서 입차, 출차에 따른 가격을 <번호, 요금> 형식으로 v에 저장.
set 자료구조를 만들어서 각 번호 별 입차 시간을 기록.

1. IN or OUT 판단
2. if) IN - map에 번호, 입차 시간 저장. + 입차 시간을 분으로 환산하여 저장.
3. if) OUT - map에서 번호에 따른 입차 시간을 찾고, 현재 시간과의 차이를 구함.
3-1. map에서 번호 삭제

4. records 순회 후 map에 남은 원소들에 대한 시간 계산.
4-1. 23:59에 출차한 것으로 해서 시간 계산.

5. 차량별 누적 시간에 따른 요금 계산.
5-1. 기본 시간보다 작거나 같으면 기본 요금. 크면 기본 시간을 뺀 뒤 단위 시간으로 나눈 값을 올림한 뒤 단위 요금 곱하기.

6. sort 함수 써서 v를 차 번호순대로 정렬.
7. answer에 v의 요금만 push_back().
*/