#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    for(auto i: my_string){
        if(isdigit(i)){ answer+=i-'0';}
    }
    return answer;
}