#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = -1;
    
    if(num == 1){
        return 0;
    }
    
    long long a = num;
    
    for(int i = 1; i <= 500; i++){
        if(a % 2) a = a * 3 + 1;
        else a /= 2;
        if(a == 1){
            answer = i;
            break;
        }
    }
    
    return answer;
}