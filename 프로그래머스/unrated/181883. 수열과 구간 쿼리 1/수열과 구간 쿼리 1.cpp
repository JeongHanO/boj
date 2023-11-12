#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> a, vector<vector<int>> q) {
    vector<int> answer;
    
    for(int i = 0; i < q.size(); i++){
        for(int j = q[i][0]; j <= q[i][1]; j++){
            a[j]++;
        }
    }
    
    return a;
}