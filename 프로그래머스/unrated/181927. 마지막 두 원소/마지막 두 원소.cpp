#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num) {
    if(num[num.size()-1] > num[num.size()-2]) num.push_back(num[num.size()-1]-num[num.size()-2]);
    else num.push_back(num[num.size()-1]*2);
    return num;
}