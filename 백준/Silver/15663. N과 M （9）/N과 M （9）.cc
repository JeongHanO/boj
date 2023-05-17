#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
int ans[9];
bool visited[9] = {false,};

void dfs(int dep){
    if(dep == m){
        for(int i = 0; i < m; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int tmp = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i] && tmp != arr[i]){
            ans[dep] = arr[i];
            tmp = ans[dep];
            visited[i] = true;
            dfs(dep+1);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> arr[i];
    sort(arr,arr+n);
    dfs(0);
}