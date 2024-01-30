#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n, 0);
        for(int i = 0; i < n; i++){
            scanf("%d", &v[i]);
        }
        sort(v.begin(), v.end());
        cout << v.front() << ' ' << v.back() << endl;
    }
}