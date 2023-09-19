#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = my_string;
    answer.erase(0, answer.size() - n);
    return answer;
}