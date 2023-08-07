#include <iostream>
using namespace std;
int ans[4][7];
int tmp[4];
int main() {
    int t[4][7];
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            cin >> t[i][j];
        }
    }
    for (int i = 1; i <= 3; i++){
        tmp[i] = (t[i][4] * 3600 + t[i][5] * 60 + t[i][6]) - (t[i][1] * 3600 + t[i][2] * 60 + t[i][3]);
        cout << tmp[i]/3600 << ' ';
        tmp[i] %= 3600;
        cout << tmp[i] /60 << ' ';
        tmp[i] %= 60;
        cout << tmp[i] << '\n';
    }
}
