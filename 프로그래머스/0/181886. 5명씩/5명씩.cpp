#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> names) {
    vector<string> answer;
    // 0, 5, 10, 15, ...
    for (int i=0;i<names.size();i+=5)
    {
        answer.push_back(names[i]);
    }
    
    
    return answer;
}