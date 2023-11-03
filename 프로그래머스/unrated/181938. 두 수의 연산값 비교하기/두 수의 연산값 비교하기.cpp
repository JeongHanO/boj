#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int a1, b1;
    string x = to_string(a) + to_string(b);
    a1 = stoi(x);
    b1 = 2 * a * b;
    return max(a1, b1);
}