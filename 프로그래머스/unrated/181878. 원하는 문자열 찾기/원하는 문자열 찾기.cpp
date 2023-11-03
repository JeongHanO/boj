#include <string>
#include <vector>

using namespace std;

int solution(string m, string p) {
    int answer = 0;
    for(int i = 0; i < m.size(); i++){
        m[i] = tolower(m[i]);
    }
    for(int i = 0; i < p.size(); i++){
        p[i] = tolower(p[i]);
    }
    if(m.find(p) != string::npos) return 1;
    
    return answer;
}