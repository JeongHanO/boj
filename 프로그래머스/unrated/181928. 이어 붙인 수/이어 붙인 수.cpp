#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int a = 0;
    int b = 0;
    
    for(int i = 0; i < num_list.size(); i++){
        if(num_list[i]%2 == 0) b = b * 10 + num_list[i];
        else a = a * 10 + num_list[i];
    }
    return a+b;
}