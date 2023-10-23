#include <string>
#include <vector>

using namespace std;

int solution(vector<int> n) {
    int a = 1;
    int b = 0;
    for(int i = 0; i < n.size(); i++){
        a *= n[i];
        b += n[i];
    }
    
    if(a <b*b) return 1;
    return 0;
}