#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool bigger(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    for(int i = 0; i < sizes.size(); i++){
        if(sizes[i][0] < sizes[i][1]){
            int tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
    }
    sort(sizes.begin(), sizes.end());
    answer = sizes[sizes.size()-1][0];
    sort(sizes.begin(), sizes.end(), bigger);
    answer *= sizes[sizes.size()-1][1];
    return answer;
}