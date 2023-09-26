#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    vector<int> v(n, 0);
    v[a-1] = 1;
    v[b-1] = 1;
    
    while(true){
        vector<int> tmp;
        answer++;
        
        for(int i = 0; i < v.size(); i+=2){
            if(v[i] == 1 && v[i+1] == 1) return answer;
            if(v[i] == 1 || v[i+1] == 1) tmp.push_back(1);
            else tmp.push_back(0);
        }
        v = tmp;
        
    }

    return answer;
}