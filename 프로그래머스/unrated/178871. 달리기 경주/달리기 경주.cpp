#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<int, string> m1;
    map<string, int> m2;
    
    for(int i = 0; i < players.size(); i++){
        m1[i] = players[i];
        m2[players[i]] = i;
    }
    
    for(int i = 0; i < callings.size(); i++){
        int called = m2[callings[i]];
        string front = m1[called-1];
        m1[called-1] = callings[i];
        m1[called] = front;
        m2[callings[i]] = called - 1;
        m2[front] = called;
    }
    for(auto c: m1) answer.push_back(c.second);
    
    return answer;
}