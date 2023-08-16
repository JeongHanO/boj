#include <iostream>
#include <queue>
#include <string>
#include <stack>
using namespace std;

stack<char> stk;
string str;
string check;

void checkBoom(int checkStrLength){
    stack<char> tmpStk;
    for(int i = 0; i < checkStrLength; i++){
        char tmpChar = stk.top();
        stk.pop();
        tmpStk.push(tmpChar);
        if(check[checkStrLength-i-1] != tmpChar){
            int tmpStkSize = tmpStk.size();
            for(int j = 0; j < tmpStkSize; j++){
                stk.push(tmpStk.top());
                tmpStk.pop();
            }
            return;
        }
    }
    return;
}

int main(){
    cin >> str;
    cin >> check;
    
    int checkStrLength = check.length();
    char checkChar = check[checkStrLength - 1];
    
    for(int i = 0; i < str.length(); i++){
        stk.push(str[i]);
        if(str[i] == checkChar && stk.size() >= checkStrLength){
            checkBoom(checkStrLength);
        }
    }

    string ans = "";
    if(stk.size()){
        int stkSize = stk.size();
        for(int i = 0;i < stkSize; i++){
            ans += stk.top();
            stk.pop();
        }
        for(int i = 0;i < stkSize; i++){
            cout << ans[ans.length()-i-1];
        }
    }
    else{
        cout << "FRULA";
    }
}


