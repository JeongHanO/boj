#include <string>
#include <vector>

using namespace std;

int solution(vector<int> n) {
    int a = 0;
    int b = 0;
    for(int i = 0; i < n.size(); i++){
        if(i%2==0){
            a += n[i];
        } else{
            b += n[i];
        }
    }
    return max(a,b);
}