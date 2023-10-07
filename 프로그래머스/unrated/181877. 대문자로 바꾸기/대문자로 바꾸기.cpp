#include <string>
#include <vector>

using namespace std;

string solution(string m) {
    string answer = "";
    for(int i=0; i < m.size(); i++){
        answer += toupper(m[i]);
    }
    return answer;
}