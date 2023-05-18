#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v.push_back(a);
    }

    int left = 0;
    int right = 0;
    int cnt = 0;
    while(right < n){
        int sum = 0;
        for(int j = left; j <= right; j++){
            sum += v[j];
        }
        if(sum == m){
            left++;
            right++;
            cnt++;
        }
        else if(sum < m){
            right++;
        }
        else{
            left++;
        }
        if(left > right){
            right = left;
        }
    }
    cout << cnt;
}
