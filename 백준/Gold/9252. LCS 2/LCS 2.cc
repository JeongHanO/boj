#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main(){
    string a_1, b_1;
    cin >> a_1 >> b_1;

    string a = ' ' + a_1;
    string b = ' ' + b_1;

    for(int i = 1; i < b.size(); i++){
        for(int j = 1; j < a.size(); j++){
            if(a[j] == b[i]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int row = b.size() - 1;
    int col = a.size() - 1;
    string s;
	while (dp[row][col]) {
		if (dp[row][col] == dp[row - 1][col]) {
			row--;
		}
		else if (dp[row][col] == dp[row][col - 1]) {
			col--;
		}
		else {
			s += a[col];
			row--, col--;
		}
	}

    cout << dp[b.size()-1][a.size()-1];
    if(s.size() > 0){
        reverse(s.begin(), s.end());
        cout << "\n" << s;
    }

    return 0;
}