#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int l = -1;
    int r = -1;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 2){
            if(l == -1) l = i;
            r = i;
        }
    }
    if(l == -1) return {-1};
    
    answer = vector<int> (arr.begin()+l, arr.begin()+r+1);
    
    return answer;
}