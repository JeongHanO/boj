#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int solution(vector<int> e) {
    set<int> s;
    
    for(int i = 0; i < e.size(); ++i){
        int sum = 0;
        for(int j = i; j < i + e.size(); ++j){
            int idx = j % e.size();
            sum += e[idx];
            s.emplace(sum);
        }
    }
    
    return s.size();
}