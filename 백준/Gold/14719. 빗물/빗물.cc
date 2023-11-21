#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    cin >> H >> W;

    vector<int> block(W);
    for (int i = 0; i < W; ++i) {
        cin >> block[i];
    }

    stack<int> s;
    int answer = 0;
    for (int i = 0; i < W; ++i) {
        while (!s.empty() && block[i] > block[s.top()]) {
            int top = s.top();
            s.pop();

            if (s.empty()) {
                break;
            }

            int distance = (i - s.top() - 1);
            int height = min(block[i], block[s.top()]) - block[top];

            answer += (distance * height);
        }
        s.push(i);
    }

    cout << answer << endl;

    return 0;
}
