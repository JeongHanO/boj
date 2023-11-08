#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> r) {
    int answer = 0;
    
    sort(r.begin(), r.end(), cmp);
    
    int last = -30001;
    for(int i = 0; i < r.size(); i++){
        if(r[i][0] > last){
            last = r[i][1];
            answer += 1;
            cout << last << endl;
        }
    }
    
    return answer;
}