#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    cin >> m;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        if(binary_search(v.begin(), v.end(), a)) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
}

