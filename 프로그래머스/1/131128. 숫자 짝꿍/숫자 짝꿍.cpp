#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> vx(10, 0);
    vector<int> vy(10, 0);
    for (int i = 0; i < X.length(); i++) vx[X[i] - '0']++;
    for (int i = 0; i < Y.length(); i++) vy[Y[i] - '0']++;
    for (int i = 9; i >= 0; i--)
        for (int j = 0; j < min(vx[i], vy[i]); j++) answer += to_string(i);
    return (answer.length() == 0) ? "-1" : (answer[0] == '0') ? "0" : answer;
}