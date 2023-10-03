#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int a1 = arr1.size();
    int a2 = arr2.size();
    if(a1 != a2){
        return a1 > a2 ? 1 : -1;
    }
    int sum1 = 0;
    int sum2 = 0;
    
    for(auto &i: arr1) sum1 += i;
    for(auto &i: arr2) sum2 += i;
    
    return sum1 == sum2 ? 0 : sum1 > sum2 ? 1 : -1;
}