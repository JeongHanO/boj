#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n - lost.size();
    
    vector<bool> stu_lost(n+1);
    vector<bool> stu_reserve(n+1);
    
    for(int i = 0; i < lost.size(); i++){
        stu_lost[lost[i]] = true;
    }
    
    for(int i = 0; i < reserve.size(); i++){
        stu_reserve[reserve[i]] = true;
    }
    
    for(int i = 1; i < n+1; i++){
        if(stu_lost[i]){                       
            if(stu_reserve[i]){
                stu_reserve[i] = false;
                answer++;
            }
            else if(i > 1 && stu_reserve[i-1]){
                stu_reserve[i-1] = false;
                answer++;
            }
            else if(i < n && stu_reserve[i+1] && !stu_lost[i+1]){
                stu_reserve[i+1] = false;
                answer++;
            }
        }
    }
    
    return answer;
}