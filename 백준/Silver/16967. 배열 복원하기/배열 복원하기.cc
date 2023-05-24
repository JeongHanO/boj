#include <iostream>
#include <vector>
using namespace std;

int main(){
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    
    int arr[300][300] = {0, };
    int arr_ori[300][300] = {0, };

    for(int i = 0; i < h+x; i++){
        for(int j = 0; j < w+y; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < x; i++){
        for(int j = 0; j < w; j++){
            arr_ori[i][j] = arr[i][j];
        }
    }

    for(int i = x; i < h; i++){
        for(int j = 0; j < y; j++){
            arr_ori[i][j] = arr[i][j];
        }
        for(int j = y; j < w; j++){
            arr_ori[i][j] = arr[i][j]-arr_ori[i-x][j-y];
            
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << arr_ori[i][j] << ' ';
        }
        cout << endl;
    }
}