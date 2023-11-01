#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> s) {
    int answer = 0;
    sort(s.begin(), s.end(), greater<>());
    for(int i = m-1; i < s.size(); i+=m){
        answer += s[i]*m;
    }
    return answer;
}