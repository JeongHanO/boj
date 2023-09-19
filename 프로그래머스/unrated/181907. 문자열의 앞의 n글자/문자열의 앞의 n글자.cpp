#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = my_string;
    answer.erase(n,answer.size());
    return answer;
}