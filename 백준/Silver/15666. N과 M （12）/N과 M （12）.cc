#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
int ans[9];

void dfs(int idx, int dep){
    if(dep == m){
        for(int i = 0; i < m; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int tmp = 0;
    for(int i = idx; i < n; i++){
        if(tmp != arr[i]){
            ans[dep] = arr[i];
            tmp = ans[dep];
            dfs(i, dep+1);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> arr[i];
    sort(arr,arr+n);
    dfs(0, 0);
}

