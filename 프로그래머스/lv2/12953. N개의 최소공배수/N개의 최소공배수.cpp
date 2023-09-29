#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int answer = arr[arr.size()-1];
    
    for(answer; 1; answer++){
        bool find = true;
        for(int i = 0; i < arr.size(); i++){
            if(answer%arr[i] != 0) { find = false; break; }
        }
        if(find) return answer;
    }
    
    return answer;
}