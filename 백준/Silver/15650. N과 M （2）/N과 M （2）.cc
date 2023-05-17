#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool visited[9] = {false,};

void dfs(int depth, int idx){
    if(depth == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = idx; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[depth] = i;
            dfs(depth+1,i+1);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    dfs(0,1);
}