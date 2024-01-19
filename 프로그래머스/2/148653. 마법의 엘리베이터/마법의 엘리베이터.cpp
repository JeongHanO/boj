#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int st) {
    int answer = 0;
    
    while(st > 0){
        int tmp = st % 10;
        if(tmp < 5){
            answer += tmp;
        } else if(tmp > 5){
            answer += 10-tmp;
            st += 10;
        } else if(tmp == 5){
            answer += 5;
            int tmp2 = (st / 10) % 10;
            if(tmp2 >= 5){
                st += 10;
            } 
        }
        st /= 10;
    }
    
    
    
    return answer;
}

/*
작은수부터 계산.
0~4까지는 빼는 게 좋음.
6~9까지는 더하는 게 좋음.
5의 경우는 특별함. 앞의 숫자가 빼야할 경우에는 빼는 것이 좋고, 앞의 숫자가 더해야할 경우에는 더하는 것이 좋음.
앞의 숫자가 5보다 크거나 같으면 더하는 게 이득?
*/