#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    multiset<int> hall;
    for(int i = 0; i < k && i < score.size(); i++){
        hall.insert(score[i]);
        answer.push_back(*hall.begin());
    }
    for(int i = k; i < score.size(); i++){
        if(score[i] > *hall.begin()){
            hall.erase(hall.begin());
            hall.insert(score[i]);
        }
        answer.push_back(*hall.begin());
    }
    return answer;
}