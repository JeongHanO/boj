#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for(int i = 1; i < land.size(); i++){
        for(int j = 0; j < 4; j++){
            int tmp = -1;
            for(int k = 0; k < 4; k++){
                if(k == j) continue;
                if(land[i-1][k] > tmp) tmp = land[i-1][k];
            }
            land[i][j] += tmp;
        }
    }
    
    for(int j = 0; j < 4; j++){
        if(land[land.size()-1][j] > answer) answer = land[land.size()-1][j];
    }

    return answer;
}