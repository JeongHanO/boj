#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    vector<int> v;

    int l = 0;
    int r = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
        if(l < a ) l = a;
        r += a;
    }
    
    while(l <= r){
        int mid = (l + r) /2;

        int sum = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            if(sum + v[i] > mid){
                sum = 0;
                cnt++;
            }
            sum += v[i];
        }
        if(sum != 0) cnt++;
        if(cnt > m){    
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}