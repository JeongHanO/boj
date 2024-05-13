#include <iostream>
using namespace std;

bool board[51][51]; 

int main(){
    int n, m;
    cin >> n >> m;
    int ans = 10000000;

    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            char c; cin >> c;
            if(c == 'W') board[x][y] = true;
            else board[x][y] = false;
        }
    }

    for(int i = 0; i <= n-8; i++){
        for(int j = 0; j <= m-8; j++){
            int cnt = 0;
            bool check = true; // W
            for(int x = i; x < i+8; x++){
                for(int y = j; y < j+8; y++){
                    if(board[x][y] != check) cnt++;
                    check = !check;
                }
                check = !check;
            }
            if(cnt < ans) ans = cnt;
            cnt = 0;
            check = false; // B
            for(int x = i; x < i+8; x++){
                for(int y = j; y < j+8; y++){
                    if(board[x][y] != check) cnt++;
                    check = !check;
                }
                check = !check;
            }
            if(cnt < ans) ans = cnt;
        }
    }
    cout << ans << endl;
}