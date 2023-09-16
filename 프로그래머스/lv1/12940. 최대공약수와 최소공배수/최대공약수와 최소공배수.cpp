#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int r = 0;
    int tmp = n * m;
    while(m != 0){
        r = n % m;
        n = m;
        m = r;
    }
    answer.push_back(n);
    answer.push_back(tmp/n);
    return answer;
}