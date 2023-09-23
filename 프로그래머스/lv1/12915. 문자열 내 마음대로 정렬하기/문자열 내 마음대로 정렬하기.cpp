#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int idx = 0;

bool bigger(string s1, string s2){
    return s1[idx] != s2[idx] ? s1[idx] < s2[idx] : s1 < s2;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    idx = n;
    sort(strings.begin(), strings.end(), bigger);
    return strings;
}