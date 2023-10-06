#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string, int> want_um;
    for(int i = 0; i < want.size(); i++){
        want_um.insert({want[i], number[i]});
    }
    
    for(int i = 0; i <= discount.size() - 10; i++){
        unordered_map<string, int> discount_um;
        for(int j = i; j < i+10; j++){
            discount_um[discount[j]] += 1;
        }
        if(want_um == discount_um) answer++;
    }
    return answer;
}