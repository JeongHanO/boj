#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    int n=num_list.size();
    if (num_list[n-1] > num_list[n-2]) num_list.push_back(num_list[n-1]-num_list[n-2]);
    else num_list.push_back(num_list[n-1]*2);
    
    
    return num_list;
}