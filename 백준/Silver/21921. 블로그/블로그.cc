#include <iostream>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    
    int visitors[250001];
    int sum = 0;
    for(int i = 0; i < x; i++){
        cin >> visitors[i];
        sum += visitors[i];
    }

    int ans = sum;
    int cnt = 1;
    for(int i = x; i < n; i++){
        cin >> visitors[i];
        sum += visitors[i] - visitors[i-x];
        if(sum == ans){
            cnt ++;
        }
        else if(sum > ans){
            ans = sum;
            cnt = 1;
        }
    }
    
    if(!ans) cout << "SAD";
    else{
        cout << ans << '\n' << cnt;
    }
}

