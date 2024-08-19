#include <iostream>
#include <algorithm>
using namespace std;

int N;
int wine[10001];
int dp[10001];

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> wine[i];
    }
    dp[0] = 0;
    dp[1] = wine[1];
    dp[2] = dp[1] + wine[2];
    
    for(int i = 3; i <= N; i++){
        dp[i] = max({dp[i-2]+wine[i], dp[i-3]+wine[i-1]+wine[i], dp[i-1]});
    }
    cout << dp[N];
}