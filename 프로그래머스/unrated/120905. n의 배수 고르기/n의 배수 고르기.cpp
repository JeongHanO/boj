#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> nu) {
    vector<int> answer;
    for(int i = 0; i < nu.size(); i++){
        if(nu[i] % n == 0) answer.push_back(nu[i]);
    }
    return answer;
}