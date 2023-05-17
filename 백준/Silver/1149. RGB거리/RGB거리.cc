#include <iostream>
using namespace std;

int n;

int dp[1000][3];

int findMinimum(int a, int b, int c) {
    int minVal = a;  // 일단 첫 번째 값을 최소값으로 가정합니다

    if (b < minVal) {
        minVal = b;  // 두 번째 값이 현재 최소값보다 작으면 최소값을 갱신합니다
    }

    if (c < minVal) {
        minVal = c;  // 세 번째 값이 현재 최소값보다 작으면 최소값을 갱신합니다
    }

    return minVal;  // 최소값을 반환합니다
}

int coloring(){
    int tmp;
    int cost[1000][3];
    cost[0][0] = dp[0][0];
    cost[0][1] = dp[0][1];
    cost[0][2] = dp[0][2];
    for(int i = 1; i < n; i++){
        cost[i][0] = min(cost[i-1][1], cost[i-1][2]) + dp[i][0];
        cost[i][1] = min(cost[i-1][0], cost[i-1][2]) + dp[i][1];
        cost[i][2] = min(cost[i-1][0], cost[i-1][1]) + dp[i][2];
        //cout << cost[i][0] << ' '<< cost[i][1] << ' ' << cost[i][2] << endl;
    }
    return findMinimum(cost[n-1][0], cost[n-1][1], cost[n-1][2]);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
    cout << coloring();
}