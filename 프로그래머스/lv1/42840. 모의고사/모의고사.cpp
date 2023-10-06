#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> ans) {
    vector<int> answer(3);
    int two[4] = {1,3,4,5};
    int three[5] = {3,1,2,4,5};
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] == i%5+1) answer[0]++;
        if(i%2 == 0 && ans[i] == 2 || i%2 == 1 && ans[i] == two[i%8/2]) answer[1]++;
        if(ans[i] == three[i%10/2]) answer[2]++;
    }
    
    int big = *max_element(answer.begin(), answer.end());
    
    vector<int> ret;
    for(int i = 0; i < 3; i++){
        if(answer[i] >= big) ret.push_back(i+1);
    } 
    return ret;
}