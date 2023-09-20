#include <string>
#include <numeric>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = accumulate(numbers.begin(), numbers.end(), 0);
    return answer/numbers.size();
}