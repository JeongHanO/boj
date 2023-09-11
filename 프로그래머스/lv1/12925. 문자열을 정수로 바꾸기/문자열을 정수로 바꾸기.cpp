#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    bool sign = false;
    bool plus = true;
    for(auto i: s){
        if(i == '-'){
            sign = true;
            plus = false;
            continue;
        } else if (i == '+') {sign = true; continue;}
        answer *= 10;
        answer += i-'0';
    }
    if(sign && !plus) answer *= -1;
    
    return answer;
}