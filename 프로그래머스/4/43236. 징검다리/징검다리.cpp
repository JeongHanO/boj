#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    int left = 0;
    int right = distance;
    sort(rocks.begin(), rocks.end());
    
    while(left <= right){
        int mid = (left+right)/2;
        int loc = 0;
        int cnt = 0;
        for(auto i: rocks){
            int diff = i - loc;
            if(diff >= mid){
                loc = i;
            }else{
                cnt++;
            }
        }
        if(distance - loc < mid) cnt++;
        if(cnt > n){
            right = mid - 1;
        }else{
            left = mid + 1;
            answer = max(answer, mid);
        }
    }
    
    return answer;
}

/*
0 2 11 14 17 21 25
 2 9  3  3  4  4
*/