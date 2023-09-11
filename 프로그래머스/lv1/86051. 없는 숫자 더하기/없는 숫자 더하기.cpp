#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    bool check[10] = {false};
    for(int i = 0; i < numbers.size(); i++){
        check[numbers[i]] = true;
    }
    for(int i = 1; i < 10; i++){
        if(!check[i]) answer += i;
    }
    return answer;
}