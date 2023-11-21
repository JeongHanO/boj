#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my, int s, int e) {
    reverse(my.begin()+s, my.begin()+e+1);
    return my;
}