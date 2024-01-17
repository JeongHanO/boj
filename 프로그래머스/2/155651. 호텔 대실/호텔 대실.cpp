#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<vector<int>> bt;
    for(int i = 0; i < book_time.size(); i++){
        int t1 = (book_time[i][0][0] - '0') * 600 + (book_time[i][0][1] - '0') * 60 + (book_time[i][0][3] - '0') * 10 + book_time[i][0][4] - '0';
        int t2 = (book_time[i][1][0] - '0') * 600 + (book_time[i][1][1] - '0') * 60 + (book_time[i][1][3] - '0') * 10 + (book_time[i][1][4] - '0') + 10;
        bt.push_back({t1, t2});
    }
    
    sort(bt.begin(), bt.end());
    
    vector<int> room(1000, 0);
    
    for (auto i : bt) {
        int idx = 0;
        while(true){
            if(room[idx] <= i[0]){
                room[idx] = i[1];
                break;
            }
            else{
                idx++;
            }
        }
        if(idx > answer) answer = idx;
    }
    
    return answer+1;
}


/*
int room[1000]인 배열을 이용해서 방 관리. 배열에는 종료 시간+10분을 넣음.
예약을 모두 시간 시간에 맞춰서 정렬.
*/