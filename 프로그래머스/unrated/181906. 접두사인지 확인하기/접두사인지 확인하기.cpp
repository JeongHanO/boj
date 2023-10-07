#include <string>
#include <vector>

using namespace std;

int solution(string my, string is) {
    for(int i = 0; i < is.size(); i++){
        if(is[i] == my[i]) continue;
        return 0;
    }
    return 1;
}