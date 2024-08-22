#include <iostream>
using namespace std;

pair<int, int> dp[45];

int main(){
    int k; cin >> k;
    dp[0] = {1, 0};
    dp[1] = {0, 1};
    for(int i = 2; i <= k; i++){
        dp[i] = {dp[i-2].first + dp[i-1].first, dp[i-2].second + dp[i-1].second};
    }
    cout << dp[k].first << ' ' << dp[k].second;
}