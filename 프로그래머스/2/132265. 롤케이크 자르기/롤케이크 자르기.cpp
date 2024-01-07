#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> t) {
    int answer = 0;
    
    map<int, int> a;
    map<int, int> b;
    
    for(int i = 0; i < t.size(); i++){
        b[t[i]]++;
    }
    
    for(int i = 0; i < t.size(); i++){
        b[t[i]]--;
        a[t[i]]++;
        
        if(b[t[i]] == 0){
            b.erase(t[i]);
        }
        if(a.size() == b.size()){
            answer++;
        }
    }
    
    return answer;
}