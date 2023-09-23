#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    vector<int> v;
    for(int i = 1; i < food.size(); i++){
        for(int j = 0; j < food[i]/2; j++){
            v.push_back(i);
        }
    }
    for(int i = 0; i < v.size(); i++){
        answer += v[i] + '0';
    }
    answer += '0';
    for(int i = v.size() - 1; i >= 0; i--){
        answer += v[i] + '0';
    }
    return answer;
}