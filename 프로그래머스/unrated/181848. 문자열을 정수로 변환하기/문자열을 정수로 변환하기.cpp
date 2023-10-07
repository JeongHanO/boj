#include <string>
#include <vector>

using namespace std;

int solution(string n) {
    int answer = 0;
    for(int i = 0; i < n.size(); i++){
        answer = answer * 10 + (n[i]-'0');
    }
    return answer;
}