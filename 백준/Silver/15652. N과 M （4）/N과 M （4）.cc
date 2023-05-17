#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];

void dfs(int idx, int depth){
    if(depth == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = idx; i <= n; i++){
        arr[depth] = i;
        dfs(i, depth+1);
    }
    return;
}

int main(){
    cin >> n >> m;
    dfs(1,0);
}