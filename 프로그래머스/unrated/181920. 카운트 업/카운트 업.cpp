#include <string>
#include <vector>

using namespace std;

vector<int> solution(int s, int e) {
    vector<int> answer;
    for(int i = s; i <= e; i++) answer.push_back(i);
    return answer;
}