#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        a = a / 100 * 60 + a % 100 - 10;
        b = b / 100 * 60 + b % 100 + 10;
        v.push_back(make_pair(a,b));
    }

    sort(v.begin(), v.end());
    
    int ans = 0;
    int saveSt = v[0].first, saveEnd = v[0].second;
    ans = saveSt - 60 * 10;

    for(int i = 0; i < n; i++){
        int start = v[i+1].first, end = v[i].second;
        if(end > saveEnd) saveEnd = end;
        if(start-saveEnd > ans) {
            ans = start-saveEnd;
        }
    }

    if((22*60 - saveEnd) > ans) {
        ans = 22*60 - saveEnd;
    }

    if(ans > 0) cout << ans;
    else cout << 0;
}