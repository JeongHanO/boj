#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'p' || s[i] == 'P'){
           cnt++; 
        } else if(s[i] == 'y' || s[i] == 'Y'){
           cnt--; 
        }
    }
    if(cnt != 0) answer = false;
    return answer;
}