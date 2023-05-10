#include <iostream>
#include <vector>
using namespace std;

int n;

int main(){
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }   
    
    int cnt = 0; 
    for(int i=n-1;i>0;i--){
        if(v[i]<=v[i-1]){
            cnt += abs(v[i] - v[i-1]) +1;
            v[i-1] = v[i] -1;
        }
    }
    cout << cnt;
    return 0;
}