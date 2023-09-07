#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int ans = 0;
int arr[8];
int visited[8];

void dfs(int idx, int weight, int depth){
    weight += arr[idx];
    weight -= k;
    if(weight < 500) return;
    if(depth == n) {
        ans++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(i, weight, depth+1);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        visited[i] = true;
        dfs(i, 500, 1);
        visited[i] = false;
    }

    cout << ans;
    return 0;
}