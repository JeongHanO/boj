#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> s;
    for(auto i: numbers){
        s.push_back(to_string(i));
    }
    
    sort(s.begin(), s.end(), cmp);
    
    for(auto i: s){
        answer += i;
    }
    
    if (answer[0] == '0')
        answer = "0";
    
    return answer;
}