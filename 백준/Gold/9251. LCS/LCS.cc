#include <iostream>
#include <string>
using namespace std;

int dp[1001][1001];

int main(){
    int ans = 0;
    string a, b;
    cin >> a >> b;

    for(int i = 0; i <= a.size(); i++){
        for(int j = 0; j <= b.size(); j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            } else if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[a.size()][b.size()];
}