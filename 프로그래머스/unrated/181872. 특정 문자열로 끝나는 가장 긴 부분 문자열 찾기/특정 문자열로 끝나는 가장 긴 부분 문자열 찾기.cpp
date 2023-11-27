#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string myString, string pat) {
    int pos = myString.rfind(pat);
    string answer = myString.substr(0, pos+pat.size());
    
    return answer;
}