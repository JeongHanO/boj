#include <iostream>
using namespace std;

char arr[10][10];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int r, c;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j= 0; j < c; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < r; i++){
        for(int j= 0; j < c; j++){
            if(arr[i][j] == 'X') continue;
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(arr[nx][ny] == 'X' || nx < 0 || ny < 0 || nx >= r || ny >= c){
                    cnt ++;
                }
            }
            if(cnt == 3){
                cout << 1;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}