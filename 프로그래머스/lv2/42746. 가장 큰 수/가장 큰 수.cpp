#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(string a, string b){
    return a+b> b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> sorted_numbers;
    for(int i = 0; i < numbers.size(); i++){
        string s = to_string(numbers[i]);
        sorted_numbers.push_back(s);
    }
    
    sort(sorted_numbers.begin(), sorted_numbers.end(), cmp);
    
    for(int i = 0; i < sorted_numbers.size(); i++){
        if(answer == "0" && sorted_numbers[i] == "0") continue;
        answer += sorted_numbers[i];
    }
    
    return answer;
}