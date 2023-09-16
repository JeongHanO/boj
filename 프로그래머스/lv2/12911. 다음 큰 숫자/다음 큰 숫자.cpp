#include <string>
#include <vector>

using namespace std;

int cnt_1(int i){
    int cnt = 0;
    while(i > 0){
        if(i%2 == 1) cnt++;
        i /= 2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int n_1 = cnt_1(n);
    int i = n + 1;
    while(1){
        if(n_1 == cnt_1(i)) return i;
        i++;
    }
    return answer;
}