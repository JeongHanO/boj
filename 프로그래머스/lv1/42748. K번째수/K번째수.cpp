#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++){
        vector<int> tmp_arr;
        for(int j = commands[i][0]-1; j < commands[i][1]; j++){
            tmp_arr.push_back(array[j]);
        }
        sort(tmp_arr.begin(), tmp_arr.end());
        
        answer.push_back(tmp_arr[commands[i][2]-1]);
    }
    return answer;
}