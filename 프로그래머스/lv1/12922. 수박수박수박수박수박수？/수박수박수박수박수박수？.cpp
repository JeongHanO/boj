#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    bool a = true;
    while(n--){
        if(a) {answer += "수"; a = false;}
        else {answer += "박"; a = true;}
    }
    return answer;
}