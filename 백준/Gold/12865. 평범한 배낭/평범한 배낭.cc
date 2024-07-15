#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int C;
    int N;
    int K[101][100001] = { 0, };
    cin >> N >> C;
    
    vector<int> w(N + 1, 0);
    vector<int> v(N + 1, 0);
    

    for (int i = 1; i < N + 1; i++) {
        cin >> w[i] >> v[i];
    }

    /*for (int i = 0; i < N; i++) {
        K[i, 0] = 0;
    }*/

    for (int x = 1; x < N+1; x++) {
        for (int y = 1; y < C + 1; y++) {
            if (w[x] > y) {
                K[x][y] = K[x-1][y];
            }
            else {
                K[x][y] = max(K[x - 1][y], K[x-1][y-w[x]]+v[x]);
            }
        }
    }
    cout << K[N][C];
}