#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int cow[11];
    fill(cow,cow+11,-1);
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(cow[a] == -1){
            cow[a] = b;
            continue;
        }
        else if(cow[a] != b){
            cow[a] = b;
            ans++;
        }
    }
    cout << ans;
}