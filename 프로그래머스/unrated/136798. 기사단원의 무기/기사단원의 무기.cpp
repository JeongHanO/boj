#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int number, int limit, int power) {
    int answer = 1;
    for(int i = 2; i <= number; i++){
        int tmp = 0;
        for(int j = 1; j * j <= i; j++){
            if(i%j==0){
                tmp++;
                if(j*j < i) tmp++;
            }
        }
        cout << tmp << endl;
        if(tmp > limit) answer += power;
        else answer += tmp;
    }
    return answer;
}