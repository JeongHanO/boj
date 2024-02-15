#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> v(n, vector<int>(n,0));

    v[n/2][n/2] = 1;

    int num = 2;
    int dist = 2;
    int dir = 1; //1,2,3,4 | 우, 하, 좌, 상
    
    pair<int, int> loc = {n/2-1, n/2-1};
    pair<int, int> ans = {n/2, n/2};

    for(int i = 0; i < n*2-2; i++){
        for(int j = 0; j < dist; j++){
            if(dir == 1) loc.second++;
            else if(dir == 2) loc.first++;
            else if (dir == 3) loc.second--;
            else loc.first--;
            v[loc.first][loc.second] = num;
            if(num == k) ans = loc;
            num++;
        }
        dir = dir%4+1;
        if(dir == 1) {
            dist += 2;
            loc.first--;
            loc.second--;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    cout << ans.first+1 << ' ' << ans.second+1;
    return 0;
}