#include <iostream>
#include <algorithm>
using namespace std;

int n;
int triangle[500][500];
int dp[500][500];

int tri_dp(){
    dp[0][0] = triangle[0][0];
    int tmp = dp[0][0];

    for(int i = 2; i <= n; i++){
        for(int j = 0; j < i; j++){
            if(j == 0){
                dp[i-1][j] = dp[i-2][j]+triangle[i-1][j];
            }
            else if(j == i-1){
                dp[i-1][j] = dp[i-2][j-1]+triangle[i-1][j];
            }
            else{
                dp[i-1][j] = max(dp[i-2][j-1],dp[i-2][j])+triangle[i-1][j];
            }
            tmp = max(tmp, dp[i-1][j]);
        }
    }
    return tmp;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            cin >> triangle[i-1][j];
        }
    }
    cout <<tri_dp();
}