#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x = yellow;
    int y = 1;
    while(x >= y){
        if(2*x + 2*y + 4 == brown){
            answer.push_back(x+2);
            answer.push_back(y+2);
            break;
        }
        while(1){
            y++;
            if(yellow%y == 0) break;
        }
        x = yellow / y;
    }
    return answer;
}