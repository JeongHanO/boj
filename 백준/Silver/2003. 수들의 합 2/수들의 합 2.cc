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
    int sum = v[0];
    while(right < n){
        if(sum < m){
            sum += v[++right];
        }
        else if(sum == m){
            cnt++;
            sum += v[++right];
        }
        else{
            sum -= v[left++];
            if(left > right){
                right = left;
                sum = v[left];
            }
        }
    }
    cout << cnt;
}
