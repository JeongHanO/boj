#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    vector<int> cnt(n+1);
    int turn = 2;
    bool flag = false;
    cnt[1]++;
    
    for(int i = 1; i < words.size(); i++){
        if(words[i][0] != words[i-1][words[i-1].size()-1]){
            flag = true;
            cout << "words[i][0] : " << words[i][0] << " / words[i-1][words[i].size()-1] : " << words[i-1][words[i-1].size()-1] << endl;
        }
        for(int j = 0; j < i; j++){
            if(words[i] == words[j]) {
                flag = true;
                cout << "SAME " << i << endl;
                break;
            }
        }
        
        cnt[turn]++;
        if(flag) break;
        turn++;
        if(turn == n+1) turn = 1;
    }
    
    if(flag){
        answer.push_back(turn);
        answer.push_back(cnt[turn]);
    } else{
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}