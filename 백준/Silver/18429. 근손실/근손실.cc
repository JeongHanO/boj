#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int ans = 0;
int arr[8];
int visited[8];

void dfs(int depth, int weight){
    if(depth == n-1) {
        ans++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!visited[i] && (weight + arr[i] - k) >= 500){
            visited[i] = true;
            dfs(depth+1, weight + arr[i] - k);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    dfs(0, 500);

    cout << ans;
    return 0;
}