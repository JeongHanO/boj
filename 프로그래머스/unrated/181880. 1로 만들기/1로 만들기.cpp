#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num) {
    int answer = 0;
    int n;
    for(int i = 0; i < num.size(); i++){
        n = num[i];
        while(n > 1){
            if(n % 2 == 1){
                n--;
            }else{
                n /= 2;
                answer++;
            }
        }
    }
    return answer;
}