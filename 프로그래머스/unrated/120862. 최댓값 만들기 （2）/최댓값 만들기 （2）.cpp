#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> n) {
    int answer = 0;
    sort(n.begin(), n.end());
    answer = n[n.size()-2] * n[n.size()-1];
    int a = n[0] * n[1];
    if(a > answer) answer = a;
    return answer;
}