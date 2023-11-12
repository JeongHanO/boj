#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(auto i: s){
        answer += i-'0';
    }
    return answer%9;
}