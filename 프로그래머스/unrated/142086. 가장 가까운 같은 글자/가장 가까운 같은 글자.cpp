#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int arr[26];
    for(int i = 0; i < 26; i++){
        arr[i] = -1;
    }
    
    for(int i = 0; i < s.size(); i++){
        if(arr[s[i]-97] == -1){
            answer.push_back(-1);
        } else{
            answer.push_back(i-arr[s[i]-97]);
        }
        arr[s[i]-97] = i;
    }
    
    return answer;
}