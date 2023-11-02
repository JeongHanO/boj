#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string x = to_string(a) + to_string(b);
    string y = to_string(b) + to_string(a);
    int t = stoi(x);
    int k = stoi(y);
    
    answer = max(t, k);
    
    return answer;
}