#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
vector<int> v;

int main(){
    int ans = 0;
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int l = 1, r = v.back();

    while(l <= r){
        int cnt = 0;
        int mid = (l + r)/2;
        for(int i = 0; i <= v.size(); i++){
            cnt += v[i]/mid;
        }
        if(cnt >= m){
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}