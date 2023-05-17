#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
bool visited[8] = {false,};
int arr[8];

void dfs(int idx, int depth){
    if(depth == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[idx] = v[i];
            dfs(idx+1,depth+1);
            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());

    dfs(0,0);
}