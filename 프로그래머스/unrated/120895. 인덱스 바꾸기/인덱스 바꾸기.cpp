#include <string>
#include <vector>

using namespace std;

string solution(string m, int n1, int n2) {
    char tmp = m[n1];
    m[n1] = m[n2];
    m[n2] = tmp;
    return m;
}