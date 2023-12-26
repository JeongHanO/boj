#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stk;
    for(int i = 0; i < moves.size(); i++){
        for(int j = 0; j < board.size(); j++){
            if(board[j][moves[i]-1] != 0){
                cout << board[j][moves[i]-1] << endl;
                if(stk.empty()) stk.push(board[j][moves[i]-1]);
                else{
                    if(stk.top() == board[j][moves[i]-1]){
                        stk.pop();
                        answer+=2;
                    } else{
                        stk.push(board[j][moves[i]-1]);
                    }
                }
                board[j][moves[i]-1] = 0;
                break;
            }
        }
    }
    return answer;
}

/*
[0,0,0,0,0]
[0,0,0,0,0]
[0,2,5,0,0]
[0,2,4,4,2]
[3,5,1,3,1]

4/3/1/1/3/2/0/4
*/