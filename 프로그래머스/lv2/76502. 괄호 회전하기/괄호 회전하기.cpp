#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool isBracket(string s){
    stack<char> stk;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
        else{
            if(stk.empty()) return false;
            if(s[i] == ')' && stk.top() == '(') stk.pop();
            else if (s[i] == ']' && stk.top() == '[') stk.pop();
            else if (s[i] == '}' && stk.top() == '{') stk.pop();
        }
    }
    if(!stk.empty()) return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    
    if(isBracket(s)) answer++;
    for(int i = 1; i < s.size(); i++){
        s += s[0];
        s.erase(0,1);
        if(isBracket(s)) answer++;
    }
    
    return answer;
}